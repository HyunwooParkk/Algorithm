#include <stdio.h>
#include <string.h>

#define MAX(a,b)    ((a > b) ? a : b)

int n;  // the numeber of array
int cache[501];
int S[501];

int lis(int start){

    int next;

    if(cache[start] != -1)
        return cache[start];

    cache[start] = 1;    // it must have one.

    for(next = start + 1; next < n; next++ ){
        if(S[start] < S[next]){  // compare start value and the next value.
            cache[start] = MAX(cache[start], lis(next) + 1);
        }
    }
    return cache[start];
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

        scanf("%d", &n);
        if(n>501 || n < 1) return -1;


        for(i=0;i<n;i++){
            scanf("%d", &S[i]);
        }

        for(i=0;i<n;i++){  // start 0 to n.
            res = MAX(res, lis(i));
        }

        printf("%d\n",res);
    }


#ifdef print

    for(k=0; k<c; k++){
        for(i=0;i<n;i++){
            printf("%d ", S[i]);
        }
        printf("\n");
    }

#endif

    return 0;

}
