/*动态内存分配*/
/*用动态内存分配的方式去定义一个能让用户自定义大小的数组*/
#include <stdio.h>
#include <stdlib.h>//编译预处理，以调用malloc函数

int main(void)
{
    int *arr = 0;//养成好习惯，定义指针时初始化为0，当malloc不起效时free仍能正确
    //如果是void *p;free(p);则free没有检测到p里面的地址是来自malloc的，而free只认malloc给的地址，程序就会出错
    //如果是void *p = 0;free(p);则free（0）就等于什么也不做，free就不会报错错，程序正常运行；
    int number;
    scanf("%d",&number);
    arr = (int*)malloc(number * sizeof(int));//调用malloc函数索要了一块想要内存，再把其类型强制转化为int，最后把这块内存的首地址交给了数组指针

    int i;
    for(i = 0; i < number; i++)
    {
        *(arr + i) = i;
        //其实也能写成arr[i] = i，二者等价
    }

    for(i = number - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);//只能还申请来的空间的最初首地址

    return 0;
}