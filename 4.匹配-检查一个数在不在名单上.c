/*现有一组数据，让用户输入一个数字，判断其是否在这组数据里面，有就输出位置，没有就输出不存在*/
#include <stdio.h>
int search(int x, int database[], int length);

int main(void)
{
    int x;
    int location;
    int database[] = {21,56,34,98,56,22,31,78,93,28};
    
    /*读取用户输入的数字*/
    printf("请输入一个数字。\n");
    scanf("%d",&x);

    /*调用函数搜索位置*/
    location = search(x, database, sizeof(database)/sizeof(database[0]));//当数组作为函数的参数时，需再用一个参数来传入其大小，大小用sizeof计算表示

    /*结果反馈*/
    if(location != -1)//匹配成功
    {
        printf("从零号位开始数，数字%d在数据库的第%d个位置上\n",x,location);
    }
    else//匹配失败
    {
        printf("数字%d不存在！\n",x);
    }

    return 0;
}

/*如何匹配*/
//需要用到主函数里的三个数据进行匹配：关键词（用户输入的数）、数组-数组长度（其实是数组的一部分，只是没法和数组一起传递过来，因此只能另用一个参数传递）
int search(int key, int database[], int length)
{
    int ret = -1;//预先设计好匹配不成功的返还值，然后再看下面的检验能不能通过

    /*遍历数据库匹配关键词*/
    for(int i = 0; i < length; i++)
    {
        if(database[i] == key)
        {
            ret = i;//匹配成功就将下标作为返还值
            break;//点到为止，减少不必要的循环，提升程序 效率
        }
    }

    return ret;//最终的返还值，回到调用处
}
