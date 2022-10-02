#include "bubblesort.h"
// 指针的概念
void test01()
{
    int a = 10;
    printf("%p", &a);
}

// 多文件编程巩固
int compare(void *data1, void *data2)
{
    return *(int*)data1 > *(int*)data2;
}

void test02()
{
    int arr[] = {3, 4, 6, 7, 8, 22, 99, 43, 0, 56};
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
    for (unsigned long long i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", arr[i]);
    }
}
// 指针的定义和使用
void test03()
{
    int a = 10;
    int *p = &a;
    *p = 2000;
    // 指针的大小和类型无关，只与当前平台使用的架构有关 32位：4字节 64位：8字节
    printf("sizeof(void *) = %llu\n", sizeof(void *));
    printf("a = %d\n", a);
    printf("*p = %d\n", a);
    printf("sizeof(char *) = %llu\n", sizeof(char *));
    printf("sizeof(short *) = %llu\n", sizeof(short *));
    printf("sizeof(int *) = %llu\n", sizeof(int *));
    printf("sizeof(long *) = %llu\n", sizeof(long *));
    printf("sizeof(long long *) = %llu\n", sizeof(long long *));
    printf("sizeof(unsigned long long *) = %llu\n", sizeof(unsigned long long *));
}

// 野指针 没有一个有效地址空间的指针
void test04()
{
    // p变量没有值
    //    int *p;
    //    *p = 1000;
    //    printf("*p = %d\n", *p);

    // p有一个不合法的值
    //    int *p = 10;// 0~255留给操作系统使用
    //    *p = 1000;
    //    printf("*p = %d\n", *p);

    int m;
    int *p = &m;
    *p = 1000;
    printf("*p = %d\n", *p);
    p = NULL;
}

// 万能指针 泛型指针
void test05()
{
    void *p;
    int a = 345;
    p = &a;
    printf("%d\n", *(int *)p);
    char ch = 'R';
    p = &ch;
    printf("%c\n", *(char *)p);
}

// 指针和数组
void test06()
{
    //    int a = 10;
    //    int b;
    //    b = a;

    // 数组名是一个地址常量不可以被修改
    int a[] = {1, 2, 4};
    int b[3];
    // b = a;
    b[0] = 1;
    b[1] = 2;
    b[2] = 4;
    // p是一个变量，可以使用数组名给指针赋值
    int *p = b;
}

void test07()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);// arr[i] == *(arr + i)
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    int *p = arr;
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
}

void test08()
{
    const int a = 20;
    // a = 5;
    int *p = (int *)&a;
    *p = 650;
    printf("a = %d\n", a);
}

// const修饰指针
void test09()
{
    int a = 10;
    int b = 30;
    // 可以修改指针的指向不可以修改指针指向的变量的值
    // const int *p = &a;
    //*p = 500;
    // p = &b;

    //    int const *p = &a;
    // *p = 500;
    //     p = &b;

    // 不可以修改指针的指向可以修改指针指向的变量的值
    // int *const p = &a;
    // *p = 500;
    // p = &b;

    // 既不可以修改指针的指向也不可以修改指针指向的变量的值
    // const int *const p = &a;
    // int const*const p = &a;
    // *p = 500;
    // p = &b;
}

// 小端数据
void test10()
{
    int a = 0x12345678;
    char *p = (char *)&a;
    //printf("%p\n", *p);
    printf("%p\n", *p);
}

// 数组初始化
void test11()
{
    int arr[10] = {0};
    for (unsigned long long i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        *(arr + i) = i + 100;
    }
    int *p = arr;
    for (unsigned long long i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", *p++);
    }
}

// 指针的算术运算
void test12()
{
    int a = 10;
    int b = 20;
    char *p = (char *) &a;
    // printf("%p\n", p * 2);
    printf("p = %p, p - 1 = %p\n", p, p - 1);

    int arr[] = {1, 3, 5, 8};
    int *p2 = arr;
    p2 + 1;// 偏过一个元素--4个字节
}

void test13()
{
    int a[] = {1, 2, 4, 5, 6, 7, 8, 9, 0};
    printf("a = %llu\n", a);
    printf("a = %llu\n", &a[0]);
    printf("a + 1 = %llu\n", a + 1);
    printf("&a + 1 = %llu\n", &a + 1);
}

// 二维数组名和指针
void test14()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printf("arr = %llu\n", arr);
    printf("arr + 1 = %llu\n", arr + 1);

    printf("arr[0] = %llu\n", arr[0]);
    printf("arr[0] + 1 = %llu\n", arr[0] + 1);

    printf("&arr[0] = %llu\n", &arr[0]);
    printf("&arr[0] + 1 = %llu\n", &arr[0] + 1);

}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        puts(argv[i]);
    }
    //    test01();
    //    test02();
    //    test03();
    //    test04();
    //    test05();
    //    test07();
    //    test08();
    //    test09();
    //    test10();
    //    test11();
    //    test12();
    //    test13();
    test14();
    return 0;
}
