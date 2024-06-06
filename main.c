#include<stdio.h>
#include"header.h"
int main()
{
    int num1 = 10, num2 = 20 , result;
    result = sum(num1,num2);
    printf("%d + %d = %d\n",num1,num2,result);

    result = mul(num1,num2);
    printf("%d * %d = %d\n",num1,num2,result);
    return 0;
}