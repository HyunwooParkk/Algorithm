#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define EMPTY   0

typedef struct node{

    char data;
    struct node *link;

}stack;

stack *get_node(void){
    stack *tmp = (stack *)malloc(sizeof(stack));
    tmp->link = EMPTY;
    return tmp;
}

void push(stack **top, int data){

    stack *temp = *top;
    *top = get_node();
    (*top)->data = data;
    (*top)->link = temp;
}

char pop(stack **top){

    stack *tmp = *top;
    char c;

    if(*top == EMPTY){
        printf("stack is empty!!\n");
        return 0;
    }

    c = tmp->data;
    *top = tmp->link;
    free(tmp);

    return c;
}

int stack_empty(stack **top){

    if(*top == EMPTY)
        return 1;
    else
        return 0;
}

int finding(char s,int sw){
    int i;
    char opening[3] = {'[', '(', '{' };
    char closing[3] = {']', ')', '}' };

    for(i=0;i<3;i++){
        
        if( sw == 0 && s == opening[i])
            return i+1;
        if( sw == 1 && s == closing[i])
            return i+1;
    }

    return 0;
}


int matching(stack **top, char s[10000]){

    int i,j;

    for(i=0;s[i];i++){


            if( finding(s[i],0) > 0){
                push(top, s[i]);
            }
            else{

                if(stack_empty(top)) // ex)   ')' but stack is empty;
                    return 0;

                if(finding(s[i],1) != finding(pop(top),0)){
                    return 0;
                }

            }

    }

    return stack_empty(top);   // if stack is empty, it means matching is success.
}

int main(void){

    stack *top;
   
    int c; /// test_case
    
    char s[10000];

    memset(s,0,sizeof(s));

    int i;

//    freopen("input.txt","r",stdin);
    scanf("%d", &c);

    while(c !=0){
        top = EMPTY;
        scanf("%s", s);
  
        matching(&top, s)  ? printf("YES\n") : printf("NO\n");
        c--;
  
    }

    return 0;
}
