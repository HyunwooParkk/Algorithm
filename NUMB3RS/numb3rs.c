#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <math.h>

int n; // the number of all villages
int d; // days
int p; // village number for prison
int t; // the numeber of villages forprobability 
int *q; // village number for probability
int A[51][51];  // connection of each villages
int deg[51];  // the number of connected villages

double cache[51][101];

int conn_num(int A[51][51]){

    int i,j;

    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            if(A[i][j]){
                deg[i]++;
            }
        }
    }
}

double search(int here, int days, int q){

    int move;
    
    if(days == d){
        return (here == q) ? 1.0 : 0.0;
    }
    
    if(fabsf(cache[here][days] + 1.0 ) > FLT_EPSILON){
        return cache[here][days];
    }

    cache[here][days] = 0.0;


    for(move=0; move<n;move++){
        if(A[here][move])
            cache[here][days] += (search(move,days+1,q) / deg[here]);
    }

    return cache[here][days];

}

int main(void){


    freopen("input.txt","r",stdin);

    int c; //test_case
    int i,j,k;

    scanf("%d",&c);
    for(k=0;k<c;k++){
        memset(A,0,sizeof(A));
        memset(cache,-1.0,sizeof(cache));
        memset(deg,0,sizeof(deg));

        scanf("%d %d %d", &n,&d,&p);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d", &A[i][j]);
            }
        }

        scanf("%d", &t);
        q = (int *)malloc(sizeof(int) * t);
        for(i=0;i<t;i++){
            scanf("%d", &q[i]);
        }

        conn_num(A);
        
        for(i=0;i<t;i++){
            printf("%0.8lf ", search(p,0,q[i]));  /// what I made mistakes was day start (d) like search(p,d,q)...
            memset(cache,-1.0,sizeof(cache));
        }

        printf("\n");
        free(q);
    }


#ifdef print

        printf("n : %d d:  %d p: %d\n",n,d,p);
       for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }

       for(i=0;i<t;i++)
           printf("%d ", q[i]);
       
       printf("\n");

       for(i=0;deg[i];i++){
           printf("%d : %d\n", i, deg[i]);
       }

#endif
    return 0;
}
