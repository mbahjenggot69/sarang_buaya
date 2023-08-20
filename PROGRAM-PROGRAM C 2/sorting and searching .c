//
//#include <stdio.h>
//#include <stdbool.h>
// 
//void swap(int *xp, int *yp)
//{
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//
//void bubbleSort(int arr[], int n)
//{
//   int i, j;
//   bool swapped;
//   for (i = 0; i < n-1; i++)
//   {
//     swapped = false;
//     for (j = 0; j < n-i-1; j++)
//     {
//        if (arr[j] > arr[j+1])
//        {
//           swap(&arr[j], &arr[j+1]);
//           swapped = true;
//        }
//     }
//     
//     if (swapped == false)
//        break;
//   }
//}
// 
//void printArray(int arr[], int size)
//{
//    int i;
//    for (i=0; i < size; i++)
//        printf("%d ", arr[i]);
//    printf("n");
//}
//
//int main()
//{
//    int arr[] = {64, 34, 25, 12, 22, 11, 90};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    bubbleSort(arr, n);
//    printf("Sorted array: \n");
//    printArray(arr, n);
//    return 0;
//}

// Searching
#include <stdio.h>
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
   
    int result = search(arr, n, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}

