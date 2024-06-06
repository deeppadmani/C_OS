#include <iostream>
#include <map>
#include <cassert>
using namespace std;
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val )
    {
        if (!(keyBegin < keyEnd)) return;
        

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};


// Example test function
void IntervalMapTest() {
	interval_map<int, char> im('A');
	im.assign(1, 5, 'B');
	im.assign(2, 4, 'C');
	im.assign(3, 4, 'D');

	// Test expected values at various points
	assert(im[-1] == 'A');
	assert(im[0] == 'A');
	assert(im[1] == 'B');
	assert(im[2] == 'C');
	assert(im[3] == 'D');
	assert(im[4] == 'B');
	assert(im[5] == 'A');
    cout << "All tests passed!\n";
}

int main() {
	IntervalMapTest();
	return 0;
}