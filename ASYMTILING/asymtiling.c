#include<stdio.h>
#include<string.h>

#define MOD     1000000007

int cache[101];

int tiling(int width){

    if(width <=1)
        return 1;

    if(cache[width] != -1)
        return cache[width];

    return cache[width] = (tiling(width -1)  + tiling(width -2)) % MOD;
}

int asym(int width){

    if(width % 2 == 1){  // odd case
        return (tiling(width) - tiling(width/2) + MOD ) % MOD;
    }

    int  ret = tiling(width);
     // even case
    ret = (ret - tiling(width/2) + MOD) % MOD;   //  ex) tiling(4) - tiling(2) -> tiles remain 2 --> even case again.
    ret = (ret - tiling(width/2 - 1) + MOD) % MOD;  // ex) tiling(4) - tiling(1)  -> tiles remain 3 --> odd case

    return ret;
}

int main(void){

    int c; // test_case
    int n; // width  1 <= n <= 100
    int i;


    scanf("%d", &c);


    for(i=0; i<c; i++){
        memset(cache, -1, sizeof(cache));
        scanf("%d",&n);
        printf("%d\n", asym(n));
    }


    return 0;
}
