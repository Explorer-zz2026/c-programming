/*【字符串的两种存在形式（指针与数组）及其输入输出】*/
#include <stdio.h>

int main(void)
{ 
    /*单指针形式*/
    //一开始就要用字符串初始化这个指针(否则要用到动态内存分配)，将字符串首地址交给指针，此后不可修改
    //（且初始化伊始，无论何种形式，编译器都会先将字符串存在远处的不可修改的只读区域）
    char *arr0 = "Hello!";
    printf("%s\n",arr0);//字符串的输入输出记住一点就行：用%s，它对应字符串的首地址

    /*多指针形式*/
    //两个单指形式的组合
    char *arr1[] = 
    {
        "Nice to meet you!",
        "So what's your name?"
    };
    printf("%s\n%s\n", arr1[0], arr1[1]);

    /*一维数组形式*/
    //将只读区域的字符串拷贝一份在本地，成为一个普通数组，可以修改
    char arr2[10];
    printf("Type your name here!(No more than 9 letters):");
    scanf("%9s", arr2);//这里的9表示最多只读入9个字符保护数组，防止scanf无限制读入撑爆数组，因为正常情况下scanf遇到空白字符才停下
    printf("%s?\n", arr2);

    /*二维数组形式*/
    //两个一维数组形式的组合
    char arr3[][20] = 
    {
        "Okay,",
        "I remember it!"
    };
   printf("%s%s\n", arr3[0], arr3[1]);

    /*看看异地字符串的首地址*/
    //程序每次运行都会被分到随机的空间的但是区是不会变的，因此地址会变但是距离不会变很近
    printf("看看异地字符串的首地址\n");
    printf("%p\n", arr0);//只读区的
    printf("%p\n", arr2);//本地区的
    
    return 0;
}