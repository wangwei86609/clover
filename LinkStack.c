#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *PNode;

typedef struct LinkStack
{
    PNode top;
} LinkStack, *PLinkStack;

PLinkStack init(void)
{
    PLinkStack pStack=(PLinkStack)malloc(sizeof(struct LinkStack));
    pStack->top=NULL;
}

//链表结构： null<-p1<-p2, 是从右到左的顺序
int push(int data,PLinkStack pStack)
{
    PNode pNode=(PNode)malloc(sizeof(struct Node));
    pNode->data=data;
    pNode->next=pStack->top;
    pStack->top=pNode;
}

int pop(PLinkStack pStack,int *data)
{
    PNode tNode=pStack->top;
    if(tNode==NULL)
    {
        return 0;
    }
    //指针类型变量取值
    *data=tNode->data;
    pStack->top=tNode->next;
    free(tNode);
    return 1;
}

int getTop(PLinkStack pStack,int *data)
{
    PNode tNode=pStack->top;
    if(tNode==NULL)
    {
        return 0;
    }
    *data=tNode->data;
    return 1;
}

void printStack(PLinkStack pStack)
{
    PNode tNode=pStack->top;
    while(tNode!=NULL)
    {
        printf("Node:%d->",tNode->data);
        tNode=tNode->next;
    }
    printf("\n");
}


int main()
{
    PLinkStack linkStack=init();
    push(1,linkStack);
    push(2,linkStack);
    push(3,linkStack);
    int data;
    pop(linkStack,&data);
    printf("pop top data=%d\n",data);

    int top;
    getTop(linkStack,&top);
    printf("current top data=%d\n",top);

    printStack(linkStack);
    return 0;
}
