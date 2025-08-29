/***************************************˫������**************************************/
/*��ʽ�洢�ṹ�Ľڵ���ֻ��һ��ָʾֱ�Ӻ�̵�ָ�����ɴˣ���ĳ���ڵ����ֻ��˳ָ�����Ѳ������
�ڵ㡣��ҪѲ��ڵ��ֱ��ǰ���������ӱ�ͷָ����������仰˵���ڵ������У�����ֱ�Ӻ�̵�ִ��ʱ
��ΪO(1)�������ֱ��ǰ����ִ��ʱ��ΪO(n)��Ϊ�˷����������ֵ����Ե�ȱ�㣬������˫������(Double
Linked List)����˫�������еĽڵ�������ָ����һ��ָ��ֱ�Ӻ�̣���һ��ָ��ֱ��ǰ����       */

//˫������ڵ㶨��
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//�������ͨ�ṹ�嶨�壬�����˽ṹ���ǩnode���Է��ڲ�����ǰ���ͺ��ʱ����
typedef struct node{
    ElemType data;
    struct node *prev,*next;
}Node;

Node* initList(void)
{
    Node *Head = (Node *)malloc(sizeof(Node));
    Head -> data = 0;
    Head -> prev = NULL;
    Head -> next = NULL;
    return Head;
}

int insertHead(Node *L,ElemType e)
{
    Node *p =(Node*)malloc(sizeof(Node));
    p -> data = e;
    p -> prev = L;
    p -> next = L ->next;
    if(L->next != NULL)
    {
        L -> next -> prev = p;
    }
    L -> next = p;
    return 1;
}

Node* get_Tail(Node* L)
{
    Node *p = L;
    while(p->next != NULL)
    {
        p = p -> next;
    }
    return p;
}

Node* insertTail(Node *tail,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p -> data = e;
    tail -> next = p;
    p -> next = NULL;
    p -> prev = tail;
    return p;
}

void listNode(Node *L)
{
    Node *p = L -> next;
    while(p != NULL)
    {
        printf("%d\n",p -> data);
        p = p ->next;
    }
}

/*****************************Test1*********************************/
/*
int main(int argc,char const *argv[])
{
    Node *list = initList();
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,30);
    listNode(list);
    return 0;
}
*/

/*****************************Test2*****************************/
int main(int argc,char const *argv[])
{
    Node *list = initList();
    Node *tail = get_Tail(list);
    tail = insertTail(tail,10);
    tail = insertTail(tail,20);
    tail = insertTail(tail,30);
    listNode(list);
    return 0;
}
