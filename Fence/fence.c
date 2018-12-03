#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MIN(a,b)    ((a < b) ? (a) : (b))
#define MAX(a,b)    ((a > b) ? (a) : (b))

int find(int *h, int left, int right){
    int ret;
    int mid;
    int low, high;
    int height;

    if (left == right) return h[left];

    mid = ( left + right ) / 2;

    ret = MAX(find(h,left, mid), find(h,mid+1, right));

    low = mid; high = mid + 1;

    height = MIN(h[low], h[high]);

    ret = MAX(ret, height * 2);

    while( left < low || high  < right){
        if(high < right && (low == left || h[low - 1] < h[high + 1])){
            high++;
            height = MIN(height, h[high]);
        }else{
            low--;
            height = MIN(height, h[low]);
        }

        ret = MAX(ret, height * (high - low + 1));
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int *h; // height
    int c;  // test_case
    int n; // number of fence
    int i,j;

    scanf("%d", &c);

    for(i=0; i<c; i++){
        scanf("%d", &n);
        h = (int *)malloc(sizeof(int) * n);

        for(j=0; j<n; j++){
            scanf("%d", &h[j]);
        }
        printf("%d\n", find(h,0, n-1));
        free(h);
    }

    /* code */
    return 0;
}
