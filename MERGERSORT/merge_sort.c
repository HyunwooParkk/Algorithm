#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size);
void merge_sort(int *arr, int *buffer, int start, int end);

int main(void)
{
	int arr[] = {3, 21, 30, 38, 25, 66, 11,6};
	int size = sizeof(arr) / sizeof(int);
	int *pbuffer = NULL;

	pbuffer = (int *)malloc( sizeof(int) * size );

	print_array(arr,size);

	if( pbuffer != NULL)
	{

		merge_sort(arr, pbuffer, 0, size-1);
		free(pbuffer);
	}

	print_array(arr,size);
}

void print_array(int *arr, int size)
{
	int i;

	for(i=0; i< size ; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge_sort(int *arr, int *buffer, int start, int end)
{
	int middle = 0;
	
	int left = 0;
	int right = 0;
	int i, k = 0;

	if(start < end )
	{
		middle = (start + end) / 2;
		left = start;
		right = middle + 1;
		k = start;

		merge_sort(arr, buffer, start, middle);
		merge_sort(arr, buffer, right, end);

		while( (left <= middle) && (right <= end) )
		{
			if( arr[left] <= arr[right] )
			{
				buffer[k] = arr[left];
				left++;
			}else
			{
				buffer[k] = arr[right];
				right++;
			}
			k++;
		}

		if(left > middle)  // 두 번째 배열이 남아 있을 경우
		{
			for( i=right; i<=end; i++,k++)
			{
				buffer[k] = arr[i];
			}
		}else // 첫번째 배열이 남아 있을 경우
		{
			for( i=left; i<=middle; i++,k++)
			{
				buffer[k] = arr[i];
			}

		}

		for(i=0; i<=end; i++)
		{
			arr[i] = buffer[i];
		}
	}

}
