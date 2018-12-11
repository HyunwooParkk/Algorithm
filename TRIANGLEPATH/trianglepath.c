#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX(a,b)    ( (a > b) ? a : b )

int triangle[100][100];
int cache[100][100];
int n; // size of triangle 2 <= n <= 100

int path(int y, int x){

    if(y == (n - 1))   // if y reaches the last row, just return value of triangle[n-1][x].
        return triangle[y][x];

    if(cache[y][x] != -1)   // if cache is not empty, return cache
        return cache[y][x];

    return cache[y][x] =  MAX(path(y+1, x), path(y+1, x+1)) + triangle[y][x];  // find max value and insert it in cache.

}


int main(){

    int c; /// test_case
    int i,j,k;


    scanf("%d", &c);

    for(k=0; k < c; k++){ // make triangle
        memset(cache, -1, sizeof(cache));  // initiating cache and triangle value are the most important routine!!!!
        memset(triangle, 0, sizeof(triangle));
        scanf("%d", &n);
        for(i=0; i < n; i++){
            for(j=0; j <= i; j++){
                scanf("%d", &triangle[i][j]);
            }
        }

        printf("%d\n", path(0,0));
    }


#ifdef print

    for(k=0; k < c; k++){
        for(i=0; i < n; i++){
            for(j=0; j <= i; j++){
                printf("%d", triangle[i][j]);
            }
            printf("\n");
        }
    }

#endif
}
