/*【内存泄漏】*/
/*其实这个程序是执行不了的*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = 0;
    int cnt = 0;
    while((p = (int*)malloc(100 * 1024 * 1024)))//循环里内存地址被反复覆改——原地址丢失，且每次申请的内存都没有free返还——内存泄漏
    {
        cnt++;
    }

    printf("本次一共申请到%d00MB的内存空间。\n", cnt);

    return 0;
}