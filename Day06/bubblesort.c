#include "bubblesort.h"
#include <stdlib.h>
#include <string.h>
// int数组的类型为 int [] 而不是int
void bubbleSort(void *arr, unsigned long long size, unsigned long long eleLen, int (*compare)(void *data1, void *data2))
{
    for (unsigned long long i = 0; i < size - 1; i++) {
        for (unsigned long long j = 0; j < size - 1 - i; j++) {
            if (compare((char *)arr + j * eleLen, (char *)arr + (j + 1) * eleLen)) {
                void *buff = malloc(eleLen);
                if (NULL == buff) {
                    return;
                }
                memcpy_s(buff, eleLen, (char *)arr + j * eleLen, eleLen);
                memcpy_s((char *)arr + j * eleLen, eleLen, (char *)arr + (j + 1) * eleLen, eleLen);
                memcpy_s((char *)arr + (j + 1) * eleLen, eleLen, buff, eleLen);
                free(buff);
                buff = NULL;
            }
        }
    }
}
