#include <stdio.h>

void test01()
{
    int a = 10;
    printf("%p", &a);
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}
