#include <stdio.h>
#include <float.h>
#include <string.h>
#include <math.h>

int n; // 1 <= n <=1000 depth
int m; // 1 <= m <= 1000 length


double cache[1001][2001];


double climb(int days, int climbed) 
{

    if(days == m) {
        if(climbed >= n){
            return 1;
        }else{
            return 0;
        }
    }
    if(fabsf(cache[days][climbed] +1) > FLT_EPSILON){  // programmers common mistake is comparing floating number.
        return cache[days][climbed];
    } 

    return cache[days][climbed] = 0.25 * climb(days + 1, climbed +1) + 0.75 * climb(days+1, climbed +2);

}

int main(void){

    int c; // test_case

    int i; // index

    scanf("%d", &c);

    for( i = 0 ; i < c; i++){

        memset(cache, -1, sizeof(cache));

        scanf("%d %d", &n, &m);

        printf("%0.10lf\n", climb(0,0));   // it must start 0,0. what I was wrong, It started 0, n ............!! :(
    }

    return 0;
}
