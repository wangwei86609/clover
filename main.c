/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct List{
    int *data;
    int size;
} List;


void init(List *list){
    //一维数组分配内存空间
    list->data=(int *)malloc(sizeof(int)*MAX_SIZE);
    list->size=0;

}

void insert(int element,int index,List *list){
    if(list->size>MAX_SIZE-1){
        printf("table is full, can't be insert");
    }
    int i;
    for(i=list->size+1;i>index;i--){
        list->data[i]=list->data[i-1];
    }

    list->data[index]=element;
    list->size++;
}

void delete(int index,List *list){
    if(list->size>MAX_SIZE-1){
        printf("table is full, can't be insert");
    }
    int i;
    for(i=index;i<list->size;i++){
        list->data[i]=list->data[i+1];
    }
    list->data[list->size]=0;
    list->size--;
}

void printTable(List *list){
    int i;
    for(i=0;i<list->size;i++){
        printf("data=%d,\n",list->data[i]);
    }
}


int main()
{
    //C语言中结构体，作为参数传入，相当于形参传入，如果需要改变参数的值，需要使用指针
    printf("Hello world!\n");
    List list;
    init(&list);
    insert(1,0,&list);
    insert(2,1,&list);
    insert(3,2,&list);
    insert(4,3,&list);
    insert(5,0,&list);
    insert(8,2,&list);
    printTable(&list);
    delete(2,&list);
    printf("===============\n");
    printTable(&list);
    return 0;
}*/
