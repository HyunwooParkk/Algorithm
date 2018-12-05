#include <stdio.h>
#include <malloc.h>
#include <string.h>

int cache[101][101];

int match(char W[101], char S[101], int w, int s){

    int w_size = strlen(W);
    int s_size = strlen(S);
    int skip;

    if(cache[w][s] != -1) return cache[w][s];

    while( s < s_size && w < w_size && ( W[w] == '?' || W[w] == S[s])){
        ++w;
        ++s;
    }

    if(w == w_size){  // if pattern ends, string array would end.
        return cache[w][s] = (s == s_size);  // if o , return 1
    }

    if(W[w] == '*'){  // if W[w] is '*', w moves next 'w+1' index and W[w+1] would compare all of S[].
        for(skip =0; skip + s <= s_size; skip++){
            if(match(W, S, w+1, s + skip))  // if somthing matched, return 1
                return cache[w][s] = 1;
        }
    }

    return cache[w][s] = 0;
}

void bubleSort( char x[51][101], int num){
    int i,j;

    char tmp[101];

    for( i= 0; i < num -1; i++){
        for(j=0; j<num -1 -i; j++){
            if(strcmp( x[j], x[j+1]) > 0){
                strcpy(tmp, x[j]);
                strcpy(x[j], x[j+1]);
                strcpy(x[j+1], tmp);
            }
        }
    }
}

int main(void){

    int c; // test_case   1 <=c <=10
    int n; // the number of file names 1<= n <=50
    int i,j,k;
    int count = 0; // for bublesort
    char W[101];  // wildcard string pattern
    char *S[101]; //  string array for matching
    char res[51][101];  // this is for answer.
    memset(res, 0, sizeof(res));

    scanf("%d", &c);

    for(k=0; k<c; k++){
        memset(W, 0, sizeof(W));
        memset(S, 0, sizeof(S));
        memset(cache, -1, sizeof(cache));
        scanf("%s", W);
        scanf("%d", &n);
        for(i=0; i<n; i++){
            S[i] = (char *)malloc(sizeof(char) * 101);
            scanf("%s", S[i]);
            if(match(W,S[i], 0, 0) ){
                strcpy(res[count], S[i]);
                ++count;
            }
            memset(S, 0, sizeof(S));  /* make sure them to be initialized. */
            memset(cache, -1, sizeof(cache));
        }


    }

    bubleSort(res, count);
    for(i=0;i<count;i++){
        printf("%s\n", res[i]);
    }

    // it`s passed by test cases... I don`t know what problems happened by the other cases... somebody gives me some tips plz....
    return 0;
}
