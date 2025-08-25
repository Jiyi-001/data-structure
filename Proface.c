/*******************结构体及指针的小应用******************/
/*
#include <stdio.h>

struct point
{
    int x;
    int y;
};

int main(int argc,char const *argv[])
{
    struct point p;
    p.x = 5;
    p.y = 10;

    struct point *pp = &p;

    (*pp).x = 10;
    (*pp).y = 5;

    printf("x = %d,y = %d\n",p.x,p.y);
    printf("x = %d,y = %d\n",pp->x,pp->y);
    return 0;
}
*/
/****************动态内存分配示例-基本数据类型**************/
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char const *argv[])
{
    int *p;
    p = (int *)malloc(sizeof(int));
    *p = 5;
    printf("%d\n",*p);
    free(p);
    return 0;
}
*/
/****************动态内存分配示例-字符串**************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char const *argv[])
{
    char *s;
    s = (char *)malloc(10);
    strcpy(s,"hello");
    printf("%s\n",s);
    printf("%p\n",s);
    free(s);
    return 0;
}
*/
/***************************算法分析***************************/
/*算法要满足的5个重要特性：有穷性、确定性、可行性、输入、输出*/
/*1.时间复杂度*/
/*2.空间复杂度*/
/*3.抽象数据类型ADT(Abstract Data Type)*/