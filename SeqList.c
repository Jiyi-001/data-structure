/****************���Ա�****************/
/*���Ա���n������Ԫ�ص��������У�����n����������ͬ�������͵�*/

/****************˳���****************/
/*��һ���������ڴ浥Ԫ���δ洢���Ա�ĸ���Ԫ�أ�Ҳ����˵���߼������ڵ�Ԫ�أ�ʵ�ʵ�����洢�ռ�Ҳ��������*/

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
    printf("���Ա��ʼ���ɹ���Ŀǰ����ռ��%d\n",list.length);
    printf("Ŀǰ�ڴ�ռ��%zu�ֽ�\n",sizeof(list.data));
    return 0;
}
*/

/******************˳���β�����Ԫ��*******************/
int appendElem(SeqList *L,ElemType e){
    if(L->length >= MAXSIZE){
        printf("˳����������޷����Ԫ�أ�\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

/***********************����**************************/
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
    printf("���Ա��ʼ���ɹ���Ŀǰ����ռ��%d\n",list.length);
    printf("Ŀǰ�ڴ�ռ��%zu�ֽ�\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("˳������10��Ԫ�سɹ�!Ŀǰ����ռ��%d\n",list.length);
    ListElem(&list);
    return 0;
}
*/

/************************����һ������********************/
int insertElem(SeqList *L,int pos,ElemType e){
    if(L->length >= MAXSIZE){
        printf("˳����������޷�����Ԫ��!\n");
    }
    if(pos<1||pos>L->length){
        printf("����λ�ò��Ϸ�!\n");
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
    printf("���Ա��ʼ���ɹ���Ŀǰ����ռ��%d\n",list.length);
    printf("Ŀǰ�ڴ�ռ��%zu�ֽ�\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("˳������10��Ԫ�سɹ�!Ŀǰ����ռ��%d\n",list.length);
    ListElem(&list);
    argc = insertElem(&list,5,99);
    printf("˳������1��Ԫ�سɹ�!����Ԫ��Ϊ%d\n",list.data[argc]);
    ListElem(&list);
    return 0;
}
*/

/************************ɾ��һ��Ԫ��********************/
int deleteElem(SeqList *L,int pos){
    if(L->length == 0){
        printf("˳���Ϊ�գ��޷�ɾ��Ԫ��!\n");
        return 0;
    }
    if(pos<1||pos>L->length){
        printf("ɾ��λ�ò��Ϸ�!\n");
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
    printf("���Ա��ʼ���ɹ���Ŀǰ����ռ��%d\n",list.length);
    printf("Ŀǰ�ڴ�ռ��%zu�ֽ�\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("˳������10��Ԫ�سɹ�!Ŀǰ����ռ��%d\n",list.length);
    ListElem(&list);
    argc = insertElem(&list,5,99);
    printf("˳������1��Ԫ�سɹ�!����Ԫ��Ϊ%d\n",list.data[argc]);
    ListElem(&list);
    int del = deleteElem(&list,5);
    printf("˳���ɾ��1��Ԫ�سɹ�!ɾ��Ԫ��Ϊ%d\n",del);
    ListElem(&list);
    return 0;
}
*/

/*********************����һ��Ԫ��**********************/
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
    printf("���Ա��ʼ���ɹ���Ŀǰ����ռ��%d\n",list.length);
    printf("Ŀǰ�ڴ�ռ��%zu�ֽ�\n",sizeof(list.data));

    for(int i=0;i<10;i++){
        appendElem(&list,i);
    }
    printf("˳������10��Ԫ�سɹ�!Ŀǰ����ռ��%d\n",list.length);
    ListElem(&list);
    argc = insertElem(&list,5,99);
    printf("˳������1��Ԫ�سɹ�!����Ԫ��Ϊ%d\n",list.data[argc]);
    ListElem(&list);
    int del = deleteElem(&list,5);
    printf("˳���ɾ��1��Ԫ�سɹ�!ɾ��Ԫ��Ϊ%d\n",del);
    ListElem(&list);
    int loc = locateElem(&list,99);
    if(loc){
        printf("˳������Ԫ��99�ɹ�!λ��Ϊ%d\n",loc);
    }else{
        printf("˳������Ԫ��99ʧ��!\n");
    }
    return 0;
}
*/