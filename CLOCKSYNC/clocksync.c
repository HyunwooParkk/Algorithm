#include<stdio.h>
#include<string.h>

#define INF	9999
#define SWITCHES	10
#define CLOCKS		16

#define MIN(a,b)	 ((a < b) ? (a) : (b))

		
const char linked[SWITCHES][CLOCKS]={
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15   each switch
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",
};

// checking all of clocks are heading 12 clock.
// I used counter for alined method, but this one has less time than counter.
int areAligned(int clocks[16]){
	
	int i;
	for(i=0;i<CLOCKS;i++){
		if(clocks[i] != 12)
			return 0;
	}
	return 1;
}

// add clock number.
void push(int clocks[16], int sw){

	int clock;
	for(clock =0; clock < CLOCKS; clock++){
		if(linked[sw][clock] == 'x'){
			clocks[clock] += 3;
			if(clocks[clock] == 15)  
					clocks[clock] = 3;
		}
	}
}

int solve(int clocks[16], int sw){

	int res = INF;
	int i;
	
	if(sw == SWITCHES){  // check whether 12 clcoks.
		return areAligned(clocks) ? 0 : INF;
	}

	for(i=0; i<4; i++){	// check one by one.
		res = MIN(res, i+solve(clocks, sw+1));
		push(clocks,sw);
	}

	return res;
}


int main(void){

	int c =0;
	int clocks[16];
	int res[30];
	int temp;
	int i,j;

	memset(clocks, 0, sizeof(clocks));
	memset(res, 0, sizeof(res));

	scanf("%d", &c);

	if(c>30) return -1;
	
	for( i = 0; i < c; i++){
		for(j=0;j<16;j++){
			scanf("%d", &clocks[j]);
		}
		
		temp = solve(clocks,0);
		if(temp == INF)
			printf("-1\n");
		else
			printf("%d\n", temp);

	}
	return 0;
}
