/*输出100以内（不含100）的素数，筛选范围[2,n-1]*/
/*下标放数据，函数值表示数据的性质，即array[待筛选的东西=已知有效的东西通过计算得到的无效的东西]=1或0*/
/*埃氏筛的核心思想是：“已知一个有效的东西（用下标表示它），那么由它按某种规则生成出来的东西，大概率是无效的（用函数值表示），直接全部标记掉。”*/
#include <stdio.h>
#define MAXNUMBER 100

int main(void)
{
    int prime[MAXNUMBER];

    /*初始化：先把全部数标记为1*/
    for(int i = 0; i < MAXNUMBER; i++)
    {
        prime[i] = 1;//用函数值为1代表示素数
    }

    /*再标记：把非素数重新标记为0*/
    for(int number = 2; number < MAXNUMBER; number++)//number即待筛选的数
    {
        if(prime[number] == 1)//使用的数组单元是2～99
        {
            for(int i = 2; i * number < MAXNUMBER; i++)
            {
                prime[i * number] = 0;//标记非素数：把下标为该素数倍数的变量全都标记为非素数(数组下标也能运算)
            }
        }
    }

    /*输出素数*/
    for(int i = 2; i < MAXNUMBER; i++)
    {
        if(prime[i] == 1) printf("%d\t",i);/*把函数值为1的变量的下标全部输出*/
    }
    printf("\n");

    return 0;
}
