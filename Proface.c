/*******************�ṹ�弰ָ���СӦ��******************/
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
/****************��̬�ڴ����ʾ��-������������**************/
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
/****************��̬�ڴ����ʾ��-�ַ���**************/
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
