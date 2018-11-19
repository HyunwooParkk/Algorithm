#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE	1
#define FALSE	0

/*how to cover */
const int coverType[4][3][2] = {
	{{0,0}, {1,0}, {0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

/*
 by types, cover or uncover board[y][x]
 if blocks can not put right side in, return false.
 */
int set(int board[20][20], int y, int x, int type, int delta, int raw, int col){
	
	int ok = TRUE;
	int i;
	int nx, ny;

	for(i=0; i<3;i++){
		ny = y + coverType[type][i][0];
		nx = x + coverType[type][i][1];

		if( ny<0 || ny >=raw || nx <0 || nx >= col){
			ok = FALSE;
		}
		else if( (board[ny][nx] += delta) > 1 ){
			ok = FALSE;
		}
	}

	return ok;
}

int cover(int board[20][20], int raw, int col){

	int y = -1;
	int x = -1;
	int type;
	int ret = 0;
	int i,j;

	for( i = 0; i<raw; i++){
		for(j=0; j<col; j++){
			if( board[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		}
		if( y != -1) break;
	}


	if( y == -1) return 1;  // board is full.

	for(type = 0; type < 4; type++){
		if(set(board, y, x, type, 1 , raw, col))  // if board is covered by types, call itself.
			ret += cover(board,raw,col);

		set(board,y,x,type, -1, raw, col);  // erase covered blocks.
	}


	return ret;
}

int main(int argc, char**argv){


	int c; // test_case c <=30
	int h,w;  // 1 <= h,w <=20
	int i,j,k; // index
	
	int board[20][20];
	char cboard[20][20];
	int count =0; // for checking 3 times number
	char ch;

	memset(board, 0, sizeof(board));
	memset(cboard, 0, sizeof(cboard));

	scanf("%d", &c);
	scanf("%d %d", &h, &w);

	if( c>30 || h >20 || w>20 || h<1 || w<1)
		return -1;

#ifdef file	
	FILE *fd = NULL;

	fd = fopen("./data.txt","r");
	if(fd == NULL){
		printf("file open error!!\n");
		exit(0);
	}

	for(i=0;i<h;i++){

		fscanf(fd, "%s\n", cboard[i] );
	}

	for(i=0; i<h;i++){
			for(j=0;j<w;j++){
				if(cboard[i][j] == '#')
					board[i][j] = 1;
				else if(cboard[i][j] == '.'){
					board[i][j] = 0;
					count++;
				}
			}
		}

		if( (count % 3 ) != 0 )
			printf("0\n");
		else
			printf("%d", cover(board, h,w));


#endif
	
	for(k=0;k<c;k++){
	
		for(i=0; i<h; i++){
			scanf("%s", cboard[i]);
		}
		for(i=0; i<h;i++){
			for(j=0;j<w;j++){
				if(cboard[i][j] == '#')
					board[i][j] = 1;
				else if(cboard[i][j] == '.'){
					board[i][j] = 0;
					count++;
				}
			}
		}

		if( (count % 3 ) != 0 )
			printf("0\n");
		else
			printf("%d", cover(board, h,w));
	}

#ifdef print
	for(i=0; i<h; i++){
		for(j=0; j<w; j++){
			printf("%d", board[i][j]);
		}
		printf("\n");
	}

#endif

	return 0;
}
