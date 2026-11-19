#include <stdio.h>
#include <string.h>

 int main(void)
{
    /*size_t strlen(const char *s)*/
    //输出纯内容长度（不包含字符串中的'/0'）
    char *len0 = "ABC";
    printf("%lu\n",strlen(len0));

    /*int strcmp(const char *s1, const char *s2)*/
    //比较字符串的大小，左大返还1，右大返还-1，相等返还0
    char *len1 = "ABCD";
    printf("%d\n",strcmp(len0, len1));

    /*char *strcpy(char *s1, const char *s2)*/
    ////将后面数组里的字符串复制到前面的数组里
    char src[] = "ABCDE";
    char dest[20]; 
    strcpy(dest, src);
    printf("dest = %s\n",dest);

    /*char *strchr(const char *s, int c)*/
    //在字符串里面找第一个该字符的地址（strrchr表示从右边开始找），没找到会返还NULL
    char *word = "ABCDEF";
    printf("%s\n", strchr(word, 'B'));
    printf("%s\n", strchr(word, 'G'));

    return 0;
}