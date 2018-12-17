#include<stdio.h>
#include<string.h>

#define MOD 1000000007

int cache[101];

int tiling(int width){  // it`s same concept of fibonacci numbers

    if(width <=1)
        return 1;

    if(cache[width] != -1){
        return cache[width];
    }

    // let suppose width is 5, we choose 2 options which are 2 parallel tiles and
    // vetical one tile. So, It means, when I select first option, width becomes 3.
    // the other option, width becomes 4.  --> t(5) = t(3) + t(4)
    // Therefore, It`s same like fibonacci numbers.

    return cache[width] = (tiling(width-1) + tiling(width-2)) % MOD;
}

int main(void){

    int c; //test_case
    int n; // 1 <= n <= 100

    int i,j;

    scanf("%d", &c);
    for(i=0;i<c;i++){
        memset(cache,-1,sizeof(cache));
        scanf("%d", &n);
        printf("%d\n", tiling(n));
    }

    return 0;
}
