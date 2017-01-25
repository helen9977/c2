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



typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node* LinkList; /*  定义 LinkList */


/*初始化顺序线性表*/
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node)); /*  产生头结点 */
    if(!(*L)) /*  存储分配失败 */
        return ERROR;
    (*L)->next=NULL; /*  指针域为空 */

    return OK;
}
/*判断L是否空表*/
Status ListEmpty(LinkList L)
{
    if(L->next)
        return FALSE;

    else
        return TRUE;
}

/*将L重置为空表 */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;	/*p指向第一个结点 */

    while(p)	/*	没到表尾 */
    {
        q=p->next; /*q指向p的下一个结点*/
        free(p);
        p=q;
    }
    (*L)->next=NULL;	/*  头结点指针域为空 */

    return OK;
}

/*L中数据元素个数*/
Status ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一个结点 */

    while(p)
    {
        i++;
        p=p->next;
    }

    return i;
}


/*L中第i个数据元素的值*/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;	/*  声明一结点 p */

    p = L->next;	/*  让 p 指向链表 L 的第一个结点 */
    j = 1;	  /*j 为计数器 */

    while (p && j<i)	/* p 不为空或者计数器 j 还没有等于 i 时，循环继续 */
    {
        p = p->next;	/*  让 p 指向下一个结点 */
        ++j;
    }

    if ( !p || j>i )
        return ERROR;	/*	第 i 个元素不存在 */
    *e = p->data;	/*	取第 i 个元素的数据 */

    return OK;
}


/*返回L中第 1 个与e相等的数据元素的位序*/
Status LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /*  找到这样的数据元素 */
            {
				return i;
				break;
			} 
            
        p=p->next;
    }

    return 0;
}


/*在L中第 i 个位置之前插入新的数据元素e*/
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p = *L; /*p为头结点*/
    j = 1;

    while (p && j < i)	/*  寻找第i个结点。此时，p指向的是i的前驱*/
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i)
        return ERROR;	/* 第 i 个元素不存在 */

    s = (LinkList)malloc(sizeof(Node));	/*	生成新结点 */

    s->data = e;

    s->next = p->next;	/*  将 p 的后继结点赋值给 s 的后继	*/
    p->next = s;	/*  将 s 赋值给 p 的后继 */

    return OK;
}

/*删除L的第i个数据元素*/
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int j;

    LinkList p,q;
    p = *L; /*p为头结点*/
    j = 1;

    while (p->next && j < i)  /*  遍历寻找第i个元素。此时，p指向i的前驱*/
    {
        p = p->next;
        ++j;
    }

    if (!(p->next) || j > i)
        return ERROR;	/*  第 i 个元素不存在 */

    q = p->next;
    p->next = q->next;	/*  将 q 的后继赋值给 p 的后继 */

    *e = q->data;	/*  将 q 结点中的数据给 e */
    free(q);	/*  让系统回收此结点，释放内存 */

    return OK;
}

/*显示某个数据*/
Status visit (ElemType c)
{
    printf("%d ",c);
    return OK;
}

/*操依次对L的每个数据元素输出 */

Status ListTraverse(LinkList L)
{
    LinkList p=L->next; /*p指向第一个结点*/

    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");

    return OK;
}


/*	随机产生 n 个元素的值，建立带表头结点的单链线性表 L（头插法） */
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));	/*  初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;	/*	先建立一个带头结点的单链表 */
    for (i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*	生成新结点 */
        p->data = rand()%100+1;	/*	随机生成 100 以内的数字 */
        p->next = (*L)->next;

        (*L)->next = p;	/*	插入到表头 */
    }
}


/*	随机产生 n 个元素的值，建立带表头结点的单链线性表 L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    srand(time(0));	/* 初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表的头结点 */
    r=*L;	/* r为指向尾部的结点 */
    for (i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*生成新结点 */
        p->data = rand()%100+1;	/*随机生成 100 以内的数字 */

        r->next=p;	/*将表尾终端结点的指针指向新结点，p为第一个结点 */
        r=p;	/*将当前的新结点定义为表尾终端结点 */
    }
    r->next = NULL;	/*  表示当前链表结束 */
}



