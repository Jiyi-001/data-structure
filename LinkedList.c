/**************************************************链表******************************************************/
/*
    线性表链式存储结构的特点是：用一组任意的存储单元存储线性表的数据元素（这组存储单元可以是连续的，也可以是不连续的）。
                                                                                                            */
/*
    为了表示每一个数据元素ai与其后继数据元素ai+1之间的逻辑关系，对数据元素ai来说，除了其本身的信息之外，还需要存储一个
指示其直接后继的信息（直接后继的存储位置）。这两部分信息组成数据元素ai的存储映像，称为节点（node）。               
                                                                                                            */
/*
    节点包括两个域：其中存储数据元素信息的称为数据域；存储直接后继存储位置的称为指针域。指针域中存储的信息称为指针或链
                                                                                                            */
/*  
    n个节点[ai(1≤i≤n)的存储映像]链接成一个链表，即为线性表（a1,a2，...，an）
                                                                                                            */

/********************************************链表存储结构*****************************************************/

#include  <stdio.h>
#include  <stdlib.h>

typedef int ElemType;

typedef struct {
    ElemType data;
    struct Node *next;
}Node;

Node* initList(){
    Node *Head = (Node *)malloc(sizeof(Node));
    Head -> data = 0;
    Head -> next = NULL;
    return Head;
}
/*****************************Test1*********************************/
/*
int main(){
    Node* list = initList();
    return 1;
}
                                                                    */

/*****************************单链表--头插法**************************** */
int insertHead(Node *L,ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p -> data = e;
    p -> next = L -> next;
    L -> next = p;
}

/*****************************Test1*********************************/
/*
int main()
{
    Node *list = initList();
    insertHead(list,10);
    insertHead(list,20);

}
*/

/*****************************单链表--遍历*****************************/
void listNode(Node* L)
{
    Node *p = L -> next;
    while(p != NULL)
    {
        printf("%d",p -> data);
        p = p -> next;
    }
    printf("\n");
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

/*****************************获取尾节点*****************************/

Node* get_tail(Node *L)
{
    Node *p = L -> next;
    while(p->next != NULL)
    {
        p = p -> next;
    }
    return p;
}

Node *insertTail(Node *tail,ElemType e)
{
    Node *p = (Node*) malloc(sizeof(Node));
    p -> data = e;
    tail -> next = p;
    p -> next = NULL;
    return p;
}

int main(int argc,char const *argv[])
{
    Node *list = initList();
    Node *tail = get_tail(list);

    tail = insertTail(tail,10);
    tail = insertTail(tail,20);
    tail = insertTail(tail,30);
    listNode(list);
    return 0;
}
