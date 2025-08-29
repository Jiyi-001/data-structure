/***************************************双向链表**************************************/
/*链式存储结构的节点中只有一个指示直接后继的指针域。由此，从某个节点出发只能顺指针向后巡查其他
节点。若要巡查节点的直接前驱、则必须从表头指针出发。换句话说，在单链表中，查找直接后继的执行时
间为O(1)，则查找直接前驱的执行时间为O(n)。为克服单链表这种单向性的缺点，可里用双向链表(Double
Linked List)。在双向链表中的节点有两个指针域，一个指向直接后继，另一个指向直接前驱。       */

//双向链表节点定义
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//相比于普通结构体定义，加入了结构体标签node，以防内部创建前驱和后继时出错
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
