#include<stdio.h>

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort(int* arr, int start, int end)
{
	int pivot = arr[end];
	int left = start;
	int right = end;

	if(left >= right)
		return;
	
	while(left < right)
	{
		while( (arr[left] < pivot) && (left < right))
		{
			left++;
		}
		
		while( (arr[right] >= pivot) && (left < right))
		{
			right--;
		}
		swap(&arr[left], &arr[right]);		
	}

	swap(&arr[right], &arr[end]);
	quick_sort(arr, start, left-1);
	quick_sort(arr, right+1, end);
}

void print_arr(int arr[])
{
	int i;
	
	for(i=0; i < sizeof(arr); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{

	int data[] = {70, 30, 50, 60, 80, 20, 10};
	int size = sizeof(data)/sizeof(int) ;
	print_arr(data);
	
	quick_sort(data, 0, size - 1);
	
	print_arr(data);
	return 0;
}
