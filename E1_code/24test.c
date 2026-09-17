#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    char *ret = dest;
    while ((*dest++ = *src++))
        ;
    printf("!!!!!\n");
    fflush(stdout);    // 强制刷新
    return ret;
}

int main()
{
    char a[10];
    my_strcpy(a, "hello");
    printf("%s\n", a);
    fflush(stdout);
    getchar();         // 暂停，看输出
    return 0;
}