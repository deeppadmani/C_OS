#include"header.h"
void print();
jmp_buf v;
int main()
{
    printf("Hello...\n");
    setjmp(v);
    printf("Hai...\n");
    print();
}

void print()
{
    printf("In Print...\n");
    longjmp(v,1);
    printf("In print after Long jump\n");
}
