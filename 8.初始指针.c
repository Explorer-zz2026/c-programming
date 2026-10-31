#include <stdio.h>

void f(int *address);//定义一个专门用来储存变量地址的变量

int main(void)
{
    int variable = 6;

    printf("先在主函数里输出variable的值：variable = %d\n",variable);
    printf("再在主函数里输出variable的地址：%p\n",&variable);//先输出variable的地址，输出格式说明用符号%p
    printf("\n调用函数f，把variable的地址传进去\n");
    f(&variable);//把variable的地址传入f函数，在f函数里探究指针的作用
    printf("在主函数里输出variable的最终值：value = %d\n",variable);//检验i的最终值

    return 0;
}

void f(int *address)
{
    printf("\n在f函数里输出i地址：address = %p\n",address);//address表示变量i的地址
    printf("在f函数里输出i地址上的数：*address = %d\n",*address);//这里的*address表示位于该地址上那个变量的值
    *address = 26;//这里的*address表示位于该地址的变量，现在对那个变量进行赋值
    printf("在f函数里进行操作*address = 26\n");
}
