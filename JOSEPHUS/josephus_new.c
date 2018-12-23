#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define EMPTY   0

typedef struct node{
    int data;

    struct node *link;
}Queue;

int deq_next_value;


Queue *get_queue_node(void){
    Queue *temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->link = EMPTY;
    return temp;
}

/* 
 * 일반적인 큐 형식의 삽입이다.
 *
 * */
void enqueue(Queue **head, int data){

        if(*head == EMPTY){
            *head = get_queue_node();
            (*head)->data = data;
            return ;
        }

        enqueue(&(*head)->link,data);
}

void print_queue(Queue *head){

    if(head == EMPTY){
        return ;
    }
    printf("%d ", head->data);

    print_queue(head->link);

}
/*
 *  dequeue는 일반적인 검색형 삭제 형식이다.
 *  단, 삭제한 값의 다음 값을 저장하는 부분만 추가됨.
 */
void dequeue(Queue **head){

    Queue *temp = *head;

    if(temp){
        *head = (*head)->link;
        deq_next_value = (*head)->data;
        free(temp);
        return ;
    }
}
/* 
 * K = 3이라면 3번의 삭제와 2번의 삽입이라는 개념의 함수를 만들었고 count 변수를 이용해서 함수가 호출하는 횟수를 세는 함수.
 * n = 6이라면  n - 2를 하여 count가 4가 될 떄까지 이 함수를 반복한다. 즉, 남은 숫자가 2개를 뜻함.
 */

void josephus(Queue **head, int k, int count, int n){

    int i;

    while( (n-2) != count){
        dequeue(head);
        for(i=1; i <= k-1; i++){
            enqueue(head,deq_next_value);
            dequeue(head);
        }
        count++;
    }
}

int main(void){

    Queue *head;

    int c; // test_case

    int n,k; 

    int i,j,temp ,count;

    scanf("%d",&c);

    for(i=0;i<c;i++){
        head = NULL;
        count = 0;

        scanf("%d %d", &n, &k);
        for(j=1;j<=n;j++){
            enqueue(&head,j);
        }

            josephus(&head,k,count,n);

            print_queue(head);
            printf("\n");
    }

/* *
 *
 * 진짜 어려운 방식으로 했었는데... 이런 쉬운 방식이 있었다니... 역시 소프트웨어는 이래서 핵잼이다. 해내는 맛.
 * 속도가 너무 느리네....쩝;
 * */

    return 0;
}
