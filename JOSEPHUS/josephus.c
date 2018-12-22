#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define EMPTY   0

typedef struct node{
    int data;
    int seq;

    struct node *link;
}Queue;

Queue *last_queue;


Queue *get_queue_node(void){
    Queue *temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->link = EMPTY;
    return temp;
}

/* 
 * 일반적인 큐 형식의 node에 큐의 삭제 순서를 지정해 줄 sequence 변수를 하나 추가.
 *
 * */
void enqueue(Queue **head, int data){

        if(*head == EMPTY){
            *head = get_queue_node();
            (*head)->data = data;
            (*head)->seq = data;
            return ;
        }

        enqueue(&(*head)->link,data);
}

void print_queue(Queue *head){

    if(head == EMPTY){
        return ;
    }
    printf("%d ", head->data);
//    printf("seq : %d\n", head->seq);

    print_queue(head->link);

}
/*
 *  dequeue는 일반적인 검색형 삭제 형식이다.
 *
 */
void dequeue(Queue **head, int seq){

    Queue *temp = *head;

    if(temp->seq == seq){
        *head = (*head)->link;
        last_queue = *head;

        free(temp);
        return ;
    }else{
        dequeue(&(*head)->link,seq);
    }
}
/*
 *  josephus를 풀기 위해 insert_seq라는 함수를 만듬.
 *  이 함수는 삭제된 큐의 다음 link를 last_queue로 받고 link를 시작으로 
 *  큐의 sequence 변수의 순서를 다시 지정할 수 있다.
 *  예를 들어, data : 1 2 3 4 5 6, seq : 1 2 3 4 5 6 을 가진 큐가 있고 지워진 data를 기준으로 3번째 마다
 *  데이터를 지운다고 가정하면, data : 2 3 5 6 , sequence도 2, 3 ,5 ,6이 남을 것이다. 그래서
 *  이 함수를 사용하여 data : 2 3 5 6 은 그대로 가져가며 , sequnce를 3 4 1 2 로 바꾸어 마지막으로 지워진
 *  데이터 다음 링크를 다시 1로 기준으로 삼아 순서를 재정의 할 수 있는 함수를 만들었다.
 */
void insert_seq(Queue *head, int n){// insert_sequence of queue
    
    int i=1;  // for sequnec number
    int count = 0;

    Queue *temp = last_queue;  // last_queue starts at 1.

    while(temp){
        temp->seq = i++;
        temp = temp->link;
        count++;
    }

    temp = head;

    while(temp && count != n){
        temp->seq = i++;
        temp = temp->link;
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

delete :
        /* 
         * temp 가 n = 6, k =3 이면  data 1  4  지우고 count = 2
         * temp는 4가 되고 insert_seq를 이용해서 seq를 4 3 1 2 로 변경
         * count가 0보다 크면 j = 3 부터 시작하여 dequeue
         * 그리고  count와 n - 2 가 같지 않으면 goto문을 사용하여 위의 과정을 반복!
         * */
        temp = n;

        // k == 1 또는 count = 0 으로 처음에만 쓰이고 이후는 else 구문만 사용.

        if( count == 0 || k == 1 ){  

            for(j=1;j<=temp;j+=k){
                if(j>temp || count == n-2)
                    break;

                dequeue(&head,j);
                count++;
            }

        }else{

            /*
             *  
             */
            for(j=k;j<=n-count;j+=k){
                if(j>temp)
                    break;

                dequeue(&head,j);
                count++;
                goto direct;
//                printf("dequeue, range: %d, j : %d count :%d\n", n-count,j,count);
            }

            /*
             *  k > 3 이면, k=4이고  data가 1 ,2 3 이 남았을 때에는  1을 지워야 하므로 4 % 3 으로 1번을 지운다
             *  만약 6 % 3 과 같이 나머지가 0이면 무조건 3번째를 지우면 된다.
             */

            if ( k > 3){
                if( k > (n-count) && (k % (n - count)) != 0){
//                    printf("k: %d, range : %d a : %d\n", k, (n - count) , k % (n- count));
                    dequeue(&head, k % (n-count));
                    count++;
                }else if(temp <=3 || (k % (n - count)) == 0 ){
                    dequeue(&head, 3);
                    count++;
                }
            }
        }
direct:
            temp -= count;

//            printf("insert_seq, temp  %d\n", temp);
            insert_seq(head, temp);
//            print_queue(head);
//          printf("\n");

        if(count != n-2)
            goto delete;

//            printf("%d\n",count);
            print_queue(head);
            printf("\n");
    }


    /* 
     * 후... 자료구조를 자유자재로 사용하려면 아직 멀었군... 그래도
     * 머리가 soft 해진 느낌
     * 내가 어렵게 풀긴 했지만, c로 다 구현하는게 c++보다 재밌다.
     *
     * 아놔... 손으로 매칭 다해봐도 다 결과가 맞는거 같은데 어디가 또 오답이냐...하;;
     * */

    return 0;
}
