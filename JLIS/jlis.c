#include <stdio.h>
#include <string.h>

#define MAX(a,b)    ((a > b) ? a : b)

int n,m ;  // the numeber of array
int cache[201];
long long S[201];
int jlis(int start){

    int next;

    if(cache[start] != -1)
        return cache[start];

    cache[start] = 1;    // it must have one.

    for(next = start + 1; next < n + m; next++ ){
        if(S[start] < S[next]){  // compare start value and the next value.
            cache[start] = MAX(cache[start], jlis(next) + 1);
        }
    }
    return cache[start];
}

void QuickSort(long long arr[], int left, int right) {
  int L = left, R = right;
  int temp;
  int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.


  //아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
  while (L <= R) {

  //pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
    while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
      L++;
    while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
      R--;
    //L, R 모두 최대 pivot 위치까지 이동.

    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
      if (L != R) { //같지 않은 경우만.
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      } //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
      L++; R--; //그리고 L,R 한 칸 더 진행.
    }
  }
  if (left < R)
    QuickSort(arr, left, R);
  if (L < right)
    QuickSort(arr, L, right);
}

int main(){

    int c; // test_case
    int i,k;
    int res;

    scanf("%d", &c);

    if( c > 50 || c < 1)
        return -1;

    for(k=0; k<c; k++){

        memset(S,0,sizeof(S)); 
        memset(cache,-1,sizeof(cache));
        res = 0;        // what I did mistake was that I didn`t make res to be zero...

        scanf("%d %d", &n, &m);
        if(n>501 || n < 1 || m > 501 || m < 1) return -1;


        for(i=0; i< n + m; i++){
            scanf("%lld", &S[i]);
        }

        QuickSort(S,0, n+m - 1);

        for(i=0; i < n + m; i++){
            res = MAX(res, jlis(i));
        }

        printf("%d\n",res);
    }


#ifdef print

    for(k=0; k<c; k++){
        for(i=0;i<n + m;i++){
            printf("%d ", S[i]);
        }
        printf("\n");
    }

#endif

    return 0;

}
