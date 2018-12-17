#include <stdio.h>
#include <string.h>

#define INF 987654321
#define MIN(a,b) ((a < b) ? a : b)

int n;  // 1 <= n <= 100
int s; // 1 <= s <= 10

int  pSum[101], pSqSum[101];
int cache[101][11];

void swap(int arr[101], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void qsort(int arr[101], int start, int end){

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
            swap(arr,left,right);
        }
    }

    swap(arr,start, right);

    qsort(arr,start, right-1);
    qsort(arr,right+1, end);

}

void precalc(int A[101]){  // preparing for easy calculation.
    int i;

    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];

    for(i=1; i < n; i++){
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
   
}

int minError(int start, int end){  // O(1)

    int sum = pSum[end] - (start == 0 ? 0 : pSum[start - 1]);  // partial sum from end and start.
    int sqSum = pSqSum[end] - (start == 0 ? 0 : pSqSum[start - 1]);
    int m = (int)(0.5 + (double)sum / (end - start + 1));  // rounding off to the nearest integer
    int ret = sqSum - 2 * m * sum + m * m * (end - start + 1);

//  printf("sum : %d, sqSum : %d, m : %d\n", sum,sqSum,m);
    return ret;
}

int quantize(int start, int parts){

    int i;

    /* base_case */
    if(start == n) return 0;
    /* parts = 0 means it has numbers.  1111/2222/3333, it is parts 3. and it will finish at part 1.        */
    if(parts == 0) return INF;

    if(cache[start][parts] != -1)
        return cache[start][parts];
    cache[start][parts] = INF;


    for(i=1; start + i <= n; i++){
        cache[start][parts] = MIN(cache[start][parts], minError(start, start + i - 1) + quantize(start + i, parts -1));
    }

    return cache[start][parts];
}

int main(void){

    int c; //test_case

    int A[101];  // when I use qsort, if A is global variale, it confront segment problem.
    int i,j;


    scanf("%d", &c);

    for(i = 0; i < c; i++){
        memset(A,0,sizeof(A));
        memset(pSum,0,sizeof(pSum));
        memset(pSqSum,0,sizeof(pSqSum));
        memset(cache,-1,sizeof(cache));

        scanf("%d %d", &n, &s);
        for(j = 0; j < n; j++){
            scanf("%d", &A[j]);
        }

       qsort(A,0, n-1);
       precalc(A);
       printf("%d\n",quantize(0,s));
       
    }

#ifdef print

    for(i=0;i<n;i++){
        printf("%d ", A[i]);
    }

    printf("\n");

#endif

    return 0;

}
