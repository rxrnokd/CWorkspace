#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE* next;
}node;

node *head = NULL, *tail = NULL;

int main()
{
    while(1)
    {
        int input;
        printf("연결할 데이터를 입력하세요. ");
        scanf("%d", &input);

        if(input < 0) break;

        node *newnode = (node*)malloc(sizeof(node));

        newnode -> data = input;
        newnode -> next = NULL;

        if(head == NULL) head = newnode;
        else tail -> next = newnode;

        tail = newnode;
    }   

    printf("연결리스트 현재 상태 : ");
    node *cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur -> data);
        cur = cur -> next;
    }
    puts(" ");

}   