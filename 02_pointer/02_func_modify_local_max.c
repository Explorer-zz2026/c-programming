/*【调用函数修改本地变量：找最值】*/
/*找出一组数字里的最大与最小的数*/
#include <stdio.h>
void minmax(int number[], int length, int *p1, int *p2);

int main(void)
{
    int number[] = {1,2,3,4,5,6,7,8,9,23,35,44,67,94,};
    int max, min;

    minmax(number, sizeof(number)/sizeof(number[0]), &max, &min);//

    printf("max = %d, min = %d\n", max, min);

    return 0;
}

void minmax(int number[], int length, int *p1, int *p2)
{
    *p2 = *p1 = number[0];//先以第一个变量的值作为min、max的初值
    for(int i = 1; i < length; i++)
    {
        if(number[i] > *p1)//大于前一个max的话就成为新的max
        {
            *p1 = number[i];//这里发生的是对主函数里的max进行赋值
        }
        if(number[i] < *p2)//小于前一个min的话就成为新的min
        {
            *p2 = number[i];//这里发生的是对主函数里的min进行赋值
        }
    }
}
/*指针可以传地址，实现了对同一个变量的跨函数修改*/
//一个变量只要它在内存中还活着（生命周期未结束,还是有效的），且没有被限制为只读（const），那么它占据的位置就是唯一的。
//只要我们拿到它的地址，并把这个地址传给任何函数，那个函数就可以直接修改它。