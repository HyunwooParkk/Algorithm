#include <stdio.h>
#include <string.h>


#define MAX(a,b) ( (a > b) ? a : b)

int cache[101][101];
int countCache[101][101];
int triangle[101][101];

int n; // 2 <= n <=100

int path(int y, int x){

    if(y == n -1){
        return cache[y][x] = triangle[y][x];
    }

    if(cache[y][x] != -1){
        return cache[y][x];
    }

    return cache[y][x] = MAX(path(y+1,x), path(y+1,x+1)) + triangle[y][x];

}


int count(int y, int x){
    
    
    if(y == n -1){
        return 1;
    }

    if(countCache[y][x] != -1){
        return countCache[y][x];
    }
    
    countCache[y][x] = 0;
    
    if(path(y+1, x+1) >= path(y+1,x)) countCache[y][x] += count(y+1,x+1);
    if(path(y+1, x+1) <= path(y+1,x)) countCache[y][x] += count(y+1,x);

    return countCache[y][x];
}
int main(void){

    int c; //test_case
    int i,j,k;


    scanf("%d", &c);

    for(k=0; k < c; k++){

        memset(triangle,0,sizeof(triangle));
        memset(cache,-1,sizeof(cache));
        memset(countCache,-1,sizeof(countCache));

        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0; j<=i;j++){
                scanf("%d", &triangle[i][j]);
            }
        }

        printf("%d\n", count(0,0));
    }


#ifdef print

    for(i=0; i < n; i++){
        for(j=0;j<=i;j++){
            printf("%d ", cache[i][j]);
        }
        printf("\n");
    }

#endif
    return 0;
}
