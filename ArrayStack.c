#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_SIZE 50


typedef struct ArrayStack{
    int *dataArray;
    int top;
    int size;
}ArrayStack, *PArrayStack;

PArrayStack init(){
    PArrayStack pStack=(PArrayStack)malloc(sizeof(ArrayStack));
    pStack->dataArray=(int *)malloc(DEFAULT_SIZE*sizeof(int));
    pStack->size=DEFAULT_SIZE;
    pStack->top=-1;
    return pStack;
}

int push(PArrayStack aStack,int data){
    aStack->top++;
    if(aStack->top>DEFAULT_SIZE-1){
        return 0;
    }
    aStack->dataArray[aStack->top]=data;
    return 1;
}

int pop(PArrayStack aStack,int *data){
    if(aStack->top<0){
        return 0;
    }
    *data=aStack->dataArray[aStack->top];
    aStack->top--;
    return 1;
}

void printStack(PArrayStack aStack){
    int i;
    for(i=aStack->top;i>-1;i--){
        printf("Node=%d,",aStack->dataArray[i]);
    }
    printf("\n");
}

int main()
{
    PArrayStack arrStack=init();
    push(arrStack,1);
    push(arrStack,2);
    push(arrStack,3);
    push(arrStack,4);
    int popdata;
    pop(arrStack,&popdata);
    pop(arrStack,&popdata);
    printf("pop data=%d\n",popdata);
    printStack(arrStack);
    return 0;
}
