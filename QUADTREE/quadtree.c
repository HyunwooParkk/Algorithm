#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define MAX		1000

int head = 0; 

char *reverse(char* string){

	char *upperLeft;
	char *upperRight;
	char *lowerLeft;
	char *lowerRight;

	char *res = (char *)malloc(sizeof(char) * MAX);  // allocate memory for return address.
	
	if(string[head] == 'b'){  //base case
		head++;
		return "b";
	}else if(string[head] == 'w'){
		head++;
		return "w";
	}
	
	head++;  // move on the next index.

	upperLeft = reverse(string);
	upperRight = reverse(string);
	lowerLeft = reverse(string);
	lowerRight = reverse(string);


	strcat(res,"x");
	strcat(res,lowerLeft);
	strcat(res,lowerRight);
	strcat(res,upperLeft);
	strcat(res,upperRight);

	return res;

}

int main(void){

	int c;
	int i;
	char string[MAX];

	memset(string, 0, sizeof(string));

	scanf("%d", &c);

	for(i=0; i<c; i++){
		head = 0;
		scanf("%s", string);
		printf("%s\n",reverse(string));
	}

	return 0;
}
