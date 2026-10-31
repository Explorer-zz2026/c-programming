/*程序要求：用户随机输入一些范围在[0,9]内的整数，统计每一种数字出现的次数,并给出一个确认键*/
#include <stdio.h>
#define LENGTH 10

int main(void)
{
    /*读入数字*/
    printf("请按要求输入数字，输入-1表示结束\n");
    int x;
    scanf("%d", &x);

    /*初始化数组，从零开始计数*/
    int count[LENGTH]; // 也可以直接写成int count[SIZE] = {0},对数组进行集成初始化
    for (int i = 0; i < LENGTH; i++)
        count[i] = 0;

    /*定位计数*/
    while (x != -1)
    {
        if (x >= 0 && x < LENGTH)
            count[x]++; // 拿输入的数字当下标实现定位
        
        
        scanf("%d", &x);
    }

    /*输出结果*/
    for (int i = 0; i < LENGTH; i++)
        printf("数字%d出现了%d次。\n", i, count[i]);

    return 0;
}