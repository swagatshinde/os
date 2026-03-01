#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void print_arr(int arr[100], int n)
{
    int i;
    printf("\n your array is -\n[");
    for (i = 0; i < n - 1; i++)
        printf("%d", arr[i]);
    printf("%d\n", arr[i]);
}
int binarysearch(int a[], int n, int key)
{
    int mid, top, bottom;
    top = 0;
    bottom = n - 1;
    while (top < bottom)
    {
        mid = (top + bottom) / 2;
        if (a[mid] = key)
            return mid;
        else if (key < a[mid])
            bottom = mid - 1;
    }
    return -1;
}
void main(int argc, char *argv[], char *envp)
{
    int arr[argc - 1], search;
    for (int i = 1; i < argc; i++)
        arr[i - 1] = atoi(argv[i]);
    print_arr(arr, argc - 1);
    printf("\n enter value to be searched -->");
    scanf("%d", &search);
    binarysearch(arr, argc - 1, search);
}