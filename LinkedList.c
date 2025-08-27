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

typedef struct Node{
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
    return 1;
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
    while(p != NULL)
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

/*****************************Test2*********************************/
/*
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
*/

int deleteNode(Node *L,int pos)
{
    Node *p = L;
    int i = 0;
//遍历链表，找到要删除节点的前驱。
    while(i<pos - 1)
    {
        p = p -> next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }
    if(p -> next ==NULL)
    {
        printf("删除位置不合法!\n");
        return 0;
    }
    Node *q = p->next;
    p -> next = q -> next;
    free(q);
    return 1;
}


/****************************************单链表的应用*********************************************/
/*
[2012]假定带头节点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀数据空间，例如，"loading"和
"being"的存储印象如下图所示

str1      +---+      +---+      +---+      +---+      +---+
          |   | ---> | l | ---> | o | ---> | a | ---> | d | ----
          +---+      +---+      +---+      +---+      +---+     |
                                                              +---+      +---+      +---+     
                                                              | i | ---> | n | ---> | g | ---> NULL
                                                              +---+      +---+      +---+
str2      +---+      +---+      +---+                           |
          |   | ---> | b | ---> | e | --------------------------
          +---+      +---+      +---+

    设str1和str2分别指向两个单词的头节点，链表节点结构为data|next，请设计一个时间上经可能高效的算法，找出由
str1和str2指向两个链表共同后缀的起始位置(如图字符i所在结点的位置p)。要求：
    (1)描述算法的基本设计思想
    (2)根据设计思想，采用C语言或C++语言描述算法，关键语句要注释说明
    (3)说明算法的时间复杂度
*/
/*
反转链表
*/
