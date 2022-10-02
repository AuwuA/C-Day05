#include "bubblesort.h"

void test01()
{
    int a = 10;
    printf("%p", &a);
}

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

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        puts(argv[i]);
    }
    // test01();
    test02();

    return 0;
}
