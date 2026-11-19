/*【指针：有了地址在哪里都能修改变量】*/
#include <stdio.h>

void f(int *p);//*表示该变量是指针类型，只能用来储存地址

int main(void)
{
    int a = 6;

    printf("(主函数里已经定义了int a = 6;)\n");
    printf("先在主函数里输出a的值:a = %d\n",a);
    printf("再在主函数里输出a的地址:&a = %p\n",&a);//&a表示a的地址,输出格式说明为%p
    printf("\n(然后调用函数f(int *p);,把a的地址传进去)\n");
    f(&a);//把a的地址传入f函数,在f函数里探究指针的作用
    printf("\n在主函数里输出a的最终值:a = %d\n",a);//检验a的最终值

    printf("\n总结:对于int *p = &a;,&a是变量a的地址,p是指针存储该变量的地址,*p则访问位于p那个地址上的变量a。\n");

    return 0;
}

void f(int *p)
{
    printf("在函数f里输出a地址:p = %p\n",p);//p表示变量a的地址
    printf("在函数f里输出a地址上的变量的值:*p = %d\n",*p);//这里的*p表示位于该地址上那个变量的值
    *p = 26;//这里的*p表示位于那个地址的变量,现在对那个变量进行赋值
    printf("在函数f里对主函数里的a进行赋值*p = 26\n");
}
