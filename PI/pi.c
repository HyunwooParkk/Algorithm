#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MIN(a,b)  ((a < b) ? a : b)
int INF = 987654321;

int cache[10003];

char N[10003];

char* substr(char *arr, int a, int b){

    char *temp = (char *)malloc(sizeof(char) *(b - a));
    strncpy(temp, arr + a, b-a);  // (arr + a) changes starting position of arr.

    return temp;
}

int same(char *arr){
    int i;

    for(i=1; i < strlen(arr); i++){
        if(arr[0] != arr[i])
            return 0;
    }

    return 1;
}

int arith_pro(char *arr){ // check whether it is arithmetic sequence.
    int i;

    for(i=1;i<strlen(arr) - 1;i++){
        if((arr[i+1] - arr[i]) != (arr[1] - arr[0]) ){
            return 0;
        }
    }
    return 1;
}

int alter(char *arr){  // check whther it is sequence number like 1212 or 2121212.
    int i;

    for(i=0; i < strlen(arr); i++){
        if(arr[i] != arr[i%2])
            return 0;
    }

    return 1;
}

int classify(int a,int b){ 

    char *M = substr(N, a, b);

    // if M is all the same, return 1.
    if(same(M)){
        free(M);
        return 1; 
    }
   // if M is aritithmetic sequence and d is equal 1 or -1, return 2.
    if(arith_pro(M) && ((M[1] - M[0]) == 1  || (M[1] - M[0]) == -1)){
        free(M);
        return 2;
    }

    // if M is like 1212 or 3232, return 4.
    if(alter(M)){
        free(M);
        return 4;
    }
 
    // if M is arithmetic sequence, return 5.
    if(arith_pro(M)) {
        free(M);
        return 5;
    }

    free(M);
    return 10;  // the other cases is return 10.
}

int memorize(int begin){

    int i;

    if(begin == strlen(N))
        return 0;

    if(cache[begin] != -1)
        return cache[begin];

    cache[begin] = INF;  // initial value for comparing.

    for(i=3; i <=5; i++){
        if(begin + i <= strlen(N)){
            cache[begin] = MIN(cache[begin], memorize(begin + i) + classify(begin, begin + i));
            // for example   memorize(3), classify(0,3)    starting 0 to 2 +  the other 3 to remainder.
            // memorize(4), classify(0,4)   start 3 or 4 or 5  next position.
            // memorize(5), classify(0,5)
            // you would better understand this form... classify(0,3) + memorize(3).
        }
    }

    return cache[begin];

}

int main(void){


    int c; // test_case
    int i;
    int res[51];

    memset(res,0,sizeof(res));

    scanf("%d", &c);

    if(c > 50) return -1;

    for(i=0; i<c; i++){
        memset(N,0,sizeof(N));
        memset(cache,-1,sizeof(cache));
        scanf("%s", N);
        res[i] = memorize(0);
    }

    for(i=0; i<c; i++){
        printf("%d\n", res[i]);
    }

    return 0;
}
