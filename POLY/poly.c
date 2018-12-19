#include <stdio.h>
#include <string.h>

const int MOD = 10000000;
int n; // number of square
int cache[101][101];

int poly(int n, int first){  // what I was solving this, I realized that Math is really important for algorithm...

    int second;
    int add;

    if(n == first)
        return 1;

    if(cache[n][first] != -1)
       return cache[n][first];

    cache[n][first] = 0;

    for(second=1; second <= n-first; second++){   // if n =5 . first = 1,  square remains 4 and possible second(it become first) = 1, 2 , 3 ,4
        add = second + first -1;
        add *= poly(n -first,second);
        add %= MOD;
        cache[n][first] += add;
        cache[n][first] %= MOD;
    }

    return cache[n][first];

}

int main(void){

    int c; // test_case
    int i,j;
    int res = 0;

    scanf("%d", &c);

    for(i=0; i<c; i++){
        memset(cache, -1, sizeof(cache));
        scanf("%d", &n);
        for(j=1;j<=n;j++){
            res += poly(n,j);
        }
        printf("%d\n",res%MOD);   // if you don`t use % MOD, output will be wrong answer.
        res = 0;
    }


    return 0;
}
