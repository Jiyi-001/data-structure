/****************线性表****************/
/*线性表是n个数据元素的有限序列，其中n个数据是相同数据类型的*/

/****************顺序表****************/
/*用一组连续的内存单元依次存储线性表的各个元素，也就是说，逻辑上相邻的元素，实际的物理存储空间也是连续的*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

void initList(SeqList *L){
    L->length = 0;
}

/******************Test1******************/
/*
int main(int argc,char const *argv[]){
    SeqList list;
    initList(&list);
    printf("线性表初始化成功！目前长度占用%d\n",list.length);
    printf("目前内存占用%zu字节\n",sizeof(list.data));
    return 0;
}
*/

/******************顺序表尾部添加元素*******************/
int appendElem(SeqList *L,ElemType e){
    if(L->length >= MAXSIZE){
        printf("顺序表已满，无法添加元素！\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

/***********************遍历**************************/
void ListElem(SeqList *L){
    for(int i=0;i<L->length;i++){
        printf("%d\n",L->data[i]);
    }
}

/******************Test2******************/
/*
int main(int argc,char const *argv[]){
    SeqList list;
    initList(&list);
    printf("线性表初始化成功！目前长度占用%d\n",list.length);
    printf("目前内存占用%zu字节\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("顺序表添加10个元素成功!目前长度占用%d\n",list.length);
    ListElem(&list);
    return 0;
}
*/

/************************插入一个数据********************/
int insertElem(SeqList *L,int pos,ElemType e){
    if(L->length >= MAXSIZE){
        printf("顺序表已满，无法插入元素!\n");
    }
    if(pos<1||pos>L->length){
        printf("插入位置不合法!\n");
        return 0;
    }
    if(pos <= L->length){
        for(int i=L->length-1;i>=pos-1;i--){
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = e;
        L->length++;
    }
    return pos-1;
}

/******************Test3******************/
/*
int main(int argc,char const *argv[]){
    SeqList list;
    initList(&list);
    printf("线性表初始化成功！目前长度占用%d\n",list.length);
    printf("目前内存占用%zu字节\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("顺序表添加10个元素成功!目前长度占用%d\n",list.length);
    ListElem(&list);
    argc = insertElem(&list,5,99);
    printf("顺序表插入1个元素成功!插入元素为%d\n",list.data[argc]);
    ListElem(&list);
    return 0;
}
*/

/************************删除一个元素********************/
int deleteElem(SeqList *L,int pos){
    if(L->length == 0){
        printf("顺序表为空，无法删除元素!\n");
        return 0;
    }
    if(pos<1||pos>L->length){
        printf("删除位置不合法!\n");
        return 0;
    }
    int e = L->data[pos-1];
    if(pos < L->length){
        for(int i=pos;i<L->length;i++){
            L->data[i-1] = L->data[i];
        }
    }
    L->length--;
    return e;
}

/******************Test4******************/
/*
int main(int argc,char const *argv[]){
    SeqList list;
    initList(&list);
    printf("线性表初始化成功！目前长度占用%d\n",list.length);
    printf("目前内存占用%zu字节\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("顺序表添加10个元素成功!目前长度占用%d\n",list.length);
    ListElem(&list);
    argc = insertElem(&list,5,99);
    printf("顺序表插入1个元素成功!插入元素为%d\n",list.data[argc]);
    ListElem(&list);
    int del = deleteElem(&list,5);
    printf("顺序表删除1个元素成功!删除元素为%d\n",del);
    ListElem(&list);
    return 0;
}
*/

/*********************查找一个元素**********************/
int locateElem(SeqList *L,ElemType e){
    for(int i=0;i<L->length;i++){
        if(L->data[i] == e){
            return i+1;
        }
    }
    return 0;
}

/******************Test5******************/
/*
int main(int argc,char const *argv[]){
    SeqList list;
    initList(&list);
    printf("线性表初始化成功！目前长度占用%d\n",list.length);
    printf("目前内存占用%zu字节\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("顺序表添加10个元素成功!目前长度占用%d\n",list.length);
    ListElem(&list);
    argc = insertElem(&list,5,99);
    printf("顺序表插入1个元素成功!插入元素为%d\n",list.data[argc]);
    ListElem(&list);
    int del = deleteElem(&list,5);
    printf("顺序表删除1个元素成功!删除元素为%d\n",del);
    ListElem(&list);
    int loc = locateElem(&list,99);
    if(loc){
        printf("顺序表查找元素99成功!位置为%d\n",loc);
    }else{
        printf("顺序表查找元素99失败!\n");
    }
    return 0;
}
*/