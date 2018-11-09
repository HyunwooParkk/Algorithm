#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
char board[5][6] = {0};

char *substr(char *word){
	int len = strlen(word);
	char *tmp = (char *)malloc(sizeof(char) * len);
	strcpy(tmp, word + 1);
	return tmp;
}

int inRange(int y, int x){
	if( x < 0 || x> 4 || y < 0 || y > 4) return FALSE;  // out of range
	else
		return TRUE;
}

int hasWord(int y, int x,char *word){

	int nextY, nextX;
	int dir;

	if(!inRange(y,x)) return FALSE;  

	if(board[y][x] != word[0]) return FALSE;   // compare first letter.

	if(strlen(word) == 1) return TRUE;

	for(dir =0; dir<8; dir++){
		nextY = y + dy[dir];	nextX = x + dx[dir];

		if(hasWord(nextY, nextX, substr(word)))
			return TRUE;
	}

	return FALSE;
}

int main(void){

	int test_case;
	int num;
	int i,j,k;

	int len;
	int ok = 0;
	char *words[11];
	char word[11];

	scanf("%d", &test_case);

	for(i=0; i<test_case;i++){
		for(i=0;i<5;i++){
			scanf("%s", board[i]);
		}
#ifdef print
		for(i=0;i<5;i++){
				printf("%s", board[i]);
				printf("\n");
		}
#endif

		scanf("%d",&num);

		for(i=0;i<num;i++){
			scanf("%s", word);
			len = strlen(word) + 1;	
			words[i] = (char *)malloc(sizeof(char) * len);
			strcpy(words[i], word);
		}
#ifdef print
		for(i=0;i<num;i++){
			printf("%s\n", words[i]);
		}
#endif

		for(k=0; k<num; k++){
			for(i=0;i<5;i++){
				for(j=0;j<5;j++){
					ok = hasWord(j,i,words[k]);
					if(ok){
						goto finish;
					}
				}
			}

finish:
			printf("%s ",words[k]);
			if(ok){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
			free(words[k]);
		}
	}
	return 0;
}
