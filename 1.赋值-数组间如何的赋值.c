/*数组是聚合变量，数组之间的赋值不能像单变量之间的赋值那么直接*/
#include <stdio.h>

int main(void)
{
    int array1[10] = {0,1,2,3,4,5,6,7,8,9};
    int array2[10] = {9,8,7,6,5,4,3,2,1,0};

    /*输出数组1原来的值*/
    for(int i = 0; i < 10; i++)
    {
        printf("%d\t",array1[i]);
    }    
    printf("\n");

    /*把数组2的值赋给数组1*/
    for(int i = 0; i < 10; i++)
    {
        array1[i] = array2[i];
    }

    /*输出数组1经赋值后的值*/
    for(int i = 0; i < 10; i++)
    {
        printf("%d\t",array1[i]);
    }
    printf("\n");

    return 0;
}