#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*  存储空间初始分配量 */

typedef int Status;/* Status 是函数的类型,其值是函数结果状态代码*/
typedef int ElemType;/* ElemType 类型根据实际情况而定，这里假设为 int */

typedef struct DuNode
{
    ElemType data;
    struct DuNode *prior;
    struct DuNode *next;
}DuNode;

typedef struct DuNode* DuLinkList;

/*初始化*/
Status InitDuList(DuLinkList *L)
{
    DuLinkList p,q;
    int i;
    *L = (DuLinkList)malloc(sizeof(DuNode));
    if(!(*p))
    {
        return ERROR;
    }
    (* L)->next = (* L)->prior = NULL;

    return OK;
}
/*判断是否为空*/
Status EmptyDuList (DuLinkList L)
{

    if(L->next==L->prior==NULL)
        return TRUE;
    else
        return FALSE;
}
/*清空*/
Status ClearDuList (DuLinkList *L)
{
    DuLinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;
        p->next->prior==NULL;
        free(p);
        p=q;
    }
    (*L)->next=(*L)->prior==NULL;

    return OK;
}
/*返回长度*/
Status DuListLength (DuLinkList L)
{
    int i;
    DuLinkList p;
    p=L->next;
    while(p)
    {
        ++i;
        p=p->next;
    }
    return i;
}
/*获取元素*/
Status GetDuElem (DuLinkList L,int i,ElemType *e)
{
    int j=1;
    DuLinkList p;
    p=L->next;

    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
        return ERROR;
    *e=p->data;

    return OK;
}
/*找到与e相等的元素的位置*/
Status LocateDuElem (DuLinkList L,ElemType e)
{
    int i=0;
    DuLinkList p;
    p=L->next;

    while(p)
    {
        i++;
        if(P->data==e)
            return i;
        p=p->next;

    }
    return 0;
}
/*插入元素*/
Status DuListInsert (DuLinkList *L,int i,ElemType e)
{
    int j=1;
    DuLinkList p,s,q;

    p=*L;

    while(p&&j<i)
    {
        j++;
        p=p->next;
    }
    if(!p || j>i)
    {
        return ERROR;
    }
    s=(DuLinkList)malloc(sizeof(DuNode));

    q=p->next;

    s->data=e;

    s->next=q;
    q->prior=s;

    s->prior=p;
    p->next=s;

    return OK;
}

/*删除元素*/
Status DuListDelete (DuLinkList *L,int i,ElemType e)
{
    int j;
    DuLinkList p,q,s;
    p=(*L);

    while(p->next &&j<i)
    {
        ++j;
        p=p->next;
    }
    if(!p ||j>i)
        return ERROR;

    q=p->next;
    s=q->next;

    p->next=q->next;
    s->prior=q->prior;

    *e=q->data;
    free(q);

    return OK;
}
