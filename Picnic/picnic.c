#include<stdio.h>
#include<string.h>

#define TRUE	1
#define FALSE	0


int count(int *taken, int pairs[11][11], int n){

	int i;

	int first = -1;  // find a first number of person;
	int ret;

	for(i=0; i<n; i++){  // find wheter they are friends or not;
		if(!taken[i]){  // they are not friend yet.
			first = i;
			break;
		}
	}


	if(first == -1) return 1;
	
	ret = 0;

	for(i = first + 1; i < n; i++){

		if(taken[i]) continue;

		if(  pairs[first][i]  || pairs[i][first] ){
			taken[first] = TRUE;  // matching each others.
			taken[i] = TRUE;

			ret += count(taken, pairs,n);

			taken[first] = FALSE;  // initiate taken.
			taken[i] = FALSE;
		}
	}

	return ret;
}

int main(void){

	int c; // test case

	int n; // a number of students  2 <= n <=10

	int m; // pairs of friends   m <= n * (n-1) / 2

	int pairs[11][11]; // check whether they are frineds.

	int taken[11]; // for deleting duplicated pairs.

	int i,j,k, a, b;

	int result[50];

	memset(result, 0, sizeof(result));
	
	scanf("%d", &c);

	if( c >50) return -1;

	for(k=0; k<c; k++){

		memset(pairs, 0, sizeof(pairs));
		memset(taken, 0, sizeof(taken));
		scanf("%d %d", &n, &m);

		if(n>10) return -1;

		for(i=0; i < m; i++){
			scanf("%d %d", &a, &b);
			pairs[a][b] = TRUE;
			pairs[b][a] = TRUE;
		}
	
		result[k] = count(taken, pairs, n);

	}

	for(i=0;i<c; i++){

		printf("%d\n",result[i]);
	}
	return 0;
}  // I had a big mistake..... make pairs and taken be initiated....
