/*程序要求：用户会随机输入一些数字，我们需要计算这些数字的平均数并输出大于平均数的数字，并给出一个确认键*/
#include <stdio.h>
/*宏定义常量，数组number最大容量*/
#define LENGTH 100
//根据C99标准，也能以变量的形式规定数组的大小：
//int LENGTH;
//scanf("%d",&LENGTH);
//int array[LENGTH];
//这样做的话用户要先输入他想输入的数字的个数，然后再输入数字，输入完了就自动得出结果，不需要确认键了

int main(void)
{
    int x;
    
    int number[LENGTH];//数组是一种聚合型变量，将一类变量统一表达，定义时也与单个变量一样，要有类型、名称，此外还要其所包含的变量的个数
    int count = 0;
    double sum = 0;

    /*读入数字*/
    printf("请按要求输入数字，输入-1表示结束\n");
    scanf("%d",&x);//在这可以把数字一次性输入完，数字会留在缓存区内，供scanf们依次读取，输入完后敲一次回车就行了

    /*确认键-1、记录、计数、求和*/
    while(x != -1 && count < 100)//保护数组不发生越界
    {
        /*依次记录输入的每一个数字*/
        number[count] = x;//从0递增的count与输入的x一一对应，在这个循环中正好当作每一个数组单元的下标
        /*计数*/
        count++;
        /*求和*/
        sum += x;

        scanf("%d",&x);//继续读取缓存区里的数字
    }

    /*计算平均数、找出大于平均数的数字*/
    if(count != 0)
    {
        /*计算平均数*/
        double average = sum / count;
        printf("%f\n",average);

        /*找出大于平均数的数字*/
        for(int i = 0; i < count; i++)//下标更新，遍历输出数组
            if(number[i] > average) printf("%d\n",number[i]);
    }

    return 0;
}