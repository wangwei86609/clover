/**
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int num;
    struct LNode *next;

}LNode, *LNodeList;

LNodeList init(){
  LNodeList lList=(LNodeList)malloc(sizeof(struct LNode));
  lList->num=0;
  lList->next=NULL;
  return lList;
}

void add(int num,LNodeList lList){
    LNodeList nList=(LNodeList)malloc(sizeof(struct LNode));
    nList->next=NULL;
    nList->num=num;
    LNodeList current=lList;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=nList;
}

void insert(int num,int index,LNodeList lList){
    int i=0;
    LNodeList newNode=(LNodeList)malloc(sizeof(struct LNode));
    newNode->num=num;
    LNodeList current=lList;
    while(current->next!=NULL){
        if(i==index){
            newNode->next=current->next;
            current->next=newNode;
            break;
        }
        current=current->next;
        i++;
    }
}

void delete(int index,LNodeList lList){
    int i=0;
    LNodeList current=lList->next;
    LNodeList pre=lList;
    while(current!=NULL){
        if(i==index){
            pre->next=current->next;
            free(current);
            break;
        }
        pre=current;
        current=current->next;
        i++;
    }
}

int query(int num,LNodeList lList){
    LNodeList current=lList->next;
    int i=0;
    while(current!=NULL){
        if(current->num==num){
            return i;
        }
        current=current->next;
        i++;
    }
    return -1;
}

void printAll(LNodeList lList){
    LNodeList current=lList->next;
    while(current!=NULL){
        printf("node=%d->",current->num);
        current=current->next;
    }
}
*/

/**
* 带有头结点的单链表实现线性表操作

int main(){
    LNodeList list=init();
    add(5,list);
    add(6,list);
    add(8,list);
    insert(4,0,list);
    insert(7,3,list);
    delete(0,list);
    delete(2,list);
    int index=query(8,list);
    printf("index=%d",index);
    printAll(list);
    return 1;
}
*/

