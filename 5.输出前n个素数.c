/*输出前100个素数*/
#include <stdio.h>
#define COUNT 100//寻找100个素数

int isPrime(int x, int prime[], int index);

int main(void)
{
    int prime[COUNT] = {0};//设置一个数组并初始化为0，存放找到的素数
    int index = 0;//数组中每一个单元的下标
    int i = 2;//按照素数的定义，从2开始找

    /*开始寻找*/
    while(index < COUNT)//只要没找够就继续找素数，找够为止
    {
        if(isPrime(i, prime, index))//找到一个素数就填一个数组单元，同时更新单元
        {
            prime[index++] = i;
        }
        
        i++;//下一个数字，继续寻找
    }

    /*以表格形式遍历输出*/
    for(int i = 0; i < COUNT; i++)
    {
        printf("%d",prime[i]);//只要数字没超过7位，表格还是能对齐的

        if((i + 1) % 5) 
        {
            printf("\t");//5列多行的格式
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}

int isPrime(int x, int prime[], int index)
{
    int ret = 1;//预先设计是素数的返还值，然后再进行非素数的检验
    
    for(int i = 0; i < index; i++)
    {
        if(x % prime[i] == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}
