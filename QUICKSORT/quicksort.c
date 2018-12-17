#include <stdio.h>
#include <math.h>

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void qsort(int *arr, int start, int end){

    if(start >= end)
        return ;

    int pivot = arr[start];
    int left = start + 1;
    int right = end;

    while(left <= right){
        while(arr[left] <= pivot){
            left++;
        }

        while(arr[right] > pivot){
            right--;
        }

        if(left <= right){
            swap(arr, left, right);
        }
    }

    swap(arr,start,right);

    qsort(arr, start, right-1);
    qsort(arr, right+1, end);


}

int main(void){

    int arr[] = {3,3,3,3,3,1};
    int i=0;
    for(i=0; i < sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr,0, sizeof(arr)/sizeof(int) - 1);

    for(i=0; i < sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
