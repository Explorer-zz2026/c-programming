/*【函数返正误，指针返结果】*/
/*当函数返还的状态值与结果值会混淆，那么采用指针来返还结果*/
#include <stdio.h>

int divide(int a, int b, int *pc);

int main(void)
{
    int a, b, c;
    scanf("%d%d",&a, &b);
    if(divide(a, b, &c))
    {
        printf("%d / %d = %d\n",a, b, c);
    }

    return 0;
}

int divide(int a, int b, int *pc)
{
    int ret = 1;//先假设状态是对的
    if(b == 0)
    {
        return 0;//当前状态异常，终止本次函数调用并返还0，将情况告诉主函数不可执行
    }
    else
    {
        *pc = a / b;//状态正确就进行计算，通过指针改变主函数里变量的值
    }
    return ret;//返还正确状态，告诉函数可以执行
}