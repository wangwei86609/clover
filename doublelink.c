#include<stdio.h>
#include<stdlib.h>

//线性表，双链表实现，双链表可以快速实现逆序，在某个节点可以实现向前和向后的查找
typedef struct Node{
    int data;
    struct node *prior;
    struct node *next;
}Node, *List;

Node* createNewNode(int data);

List init(){
    List list=(List)malloc(sizeof(Node));
    list->next=NULL;
    list->prior=NULL;
    list->data=0;
    return list;
}

void addNode(int data,List list){
    Node *pCurrent=list;
    while(pCurrent->next!=NULL){
        pCurrent=pCurrent->next;
    }
    Node *newNode=createNewNode(data);
    newNode->prior=pCurrent;
    pCurrent->next=newNode;
}

Node* createNewNode(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prior=NULL;
    newNode->next=NULL;
    return newNode;
}

void insert(int data, int index, List list){
    Node *pCurrent=list->next;
    int i=1;
    while(pCurrent!=NULL){
        if(i==index){
            break;
        }
        pCurrent=pCurrent->next;
        i++;
    }
    if(pCurrent==NULL){
        return;
    }
    Node *newNode=createNewNode(data);
    Node *prev=pCurrent->prior;
    newNode->prior=prev;
    newNode->next=pCurrent;
    prev->next=newNode;
    pCurrent->prior=newNode;
}

void deleteNode(int data,List list){
    Node *pCurrent=list->next;
    while(pCurrent!=NULL){
        if(pCurrent->data==data){
            break;
        }
        pCurrent=pCurrent->next;
    }
    if(pCurrent==NULL){
        return;
    }
    Node *prev=pCurrent->prior;
    Node *rear=pCurrent->next;
    prev->next=pCurrent->next;
    if(rear!=NULL){
      rear->prior=prev;
    }
    free(pCurrent);
}

void printList(List list){
    Node *pCurrent=list->next;
    while(pCurrent!=NULL){
        printf("Node =%d,",pCurrent->data);
        pCurrent=pCurrent->next;
    }
}


int main(){
    List list=init();
    addNode(1,list);
    addNode(2,list);
    addNode(3,list);
    addNode(5,list);
    printList(list);
    printf("\n");
    insert(4,4,list);
    printList(list);
    printf("\n");
    deleteNode(2,list);
    printList(list);
    return 0;
}




