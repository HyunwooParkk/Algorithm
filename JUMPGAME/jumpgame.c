#include <stdio.h>
#include <malloc.h>
#include <string.h>

int cache[100][100];

int jump(int *board[100], int y, int x, int b_size){
    int jumpsize;
    int ret;

    // base case
    if( y >= b_size || x >= b_size) return 0;  // out of size
    if( y == b_size -1 && x == b_size -1)   return 1; // reach the final points

    jumpsize = board[y][x];

    if(cache[y][x] != -1) return cache[y][x];

    ret = jump( board, y + jumpsize, x, b_size) || jump(board, y, x+ jumpsize,b_size);
    
    cache[y][x] = ret;

    return ret;

}


int main(){

    int c; // test_case
    int n; // size of frame
    int i,j,k;
    int *board[100];


    memset(board, 0, sizeof(board));
    memset(cache, -1, sizeof(cache));

    scanf("%d", &c);

    for(k =0; k < c; k++){
        scanf("%d", &n);
        for(i=0; i< n; i++){
            board[i] = (int *)malloc(sizeof(int) * n);
            for(j=0; j<n; j++){
                scanf("%d", &board[i][j]);
            }
        }
        if(jump(board, 0, 0, n)){
            printf("YES\n");
            memset(board, 0, sizeof(board));
            memset(cache, -1, sizeof(cache));
        }else{
            printf("NO\n");
            memset(board, 0, sizeof(board));
            memset(cache, -1, sizeof(cache));
        }
    }



#ifdef print

    for(i = 0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

#endif

    return 0;
}
