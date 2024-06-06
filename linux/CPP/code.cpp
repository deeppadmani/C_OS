#include <iostream>
#include <map>
#include <cassert>
#include <limits>

template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;
public:
    // Constructor associates whole range of K with val
    interval_map(V const& val)
        : m_valBegin(val)
    {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const& keyBegin, K const& keyEnd, V const& val) {
        if (!(keyBegin < keyEnd)) {
            return;
        }

        // Find the start and end iterators for the range to overwrite
        auto mapItStart = m_map.lower_bound(keyBegin);
        auto mapItend = m_map.lower_bound(keyEnd);

        // Insert val at keyBegin if needed
        if (mapItStart == m_map.begin() || std::prev(mapItStart)->second != val) {
            mapItStart = m_map.insert_or_assign(mapItStart, keyBegin, val);
        }

        // Erase all entries in the interval (keyBegin, keyEnd)
        if (mapItStart != mapItend) {
            m_map.erase(std::next(mapItStart), mapItend);
        }

        // Handle the end of the interval
        if (mapItend == m_map.end() || mapItend->first != keyEnd) {
            m_map[keyEnd] = (mapItend == m_map.end()) ? m_valBegin : mapItend->second;
        } else if (mapItend != m_map.end() && mapItend->second == std::prev(mapItend)->second) {
            m_map.erase(mapItend);
        }
    }

    // Look-up of the value associated with key
    V const& operator[](K const& key) const {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
            return m_valBegin;
        } else {
            return std::prev(it)->second;
        }
    }

    // Print the intervals in a human-readable form
    void print() const {
        K prevKey = std::numeric_limits<K>::lowest();
        V prevValue = m_valBegin;

        for (const auto& entry : m_map) {
            std::cout << "[" << prevKey << ", " << entry.first << ") -> " << prevValue << "\n";
            prevKey = entry.first;
            prevValue = entry.second;
        }

        // Print the last interval
        std::cout << "[" << prevKey << ", +∞) -> " << prevValue << "\n";
    }
};

// Example test function
void IntervalMapTest() {
    interval_map<int, char> im('A');
    im.assign(1, 5, 'B');
    im.assign(5, 10, 'C');

    im.print();
    // Test expected values at various points
    assert(im[-1] == 'A');
    assert(im[0] == 'A');
    assert(im[1] == 'B');
    assert(im[4] == 'B');
    assert(im[5] == 'C');
    assert(im[9] == 'C');
    assert(im[10] == 'A');
    std::cout << "All tests passed!\n";
}

int main() {
    IntervalMapTest();
    return 0;
}
