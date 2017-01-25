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
    ElemType data[2];
    struct Node *next;
}Node;
typedef struct Node* LinkList; /*  定义 LinkList */

/*建立一元多项式P*/
Status CreatPolyn(LinkList *P,int m)
{
    *P=(LinkList)malloc(sizeof(Node)); /*  产生头结点 */
    if(!(*P)) /*  存储分配失败 */
        return ERROR;
    (*P)->next=NULL; /*  指针域为空 */

    LinkList p,r;
    int i;
    r=*P;	/* r为指向尾部的结点 */
    for (i=0; i<m; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*生成新结点 */
        scanf("%d",&p->data[0]);
        scanf("%d",&p->data[1]);
        r->next=p;	/*将表尾终端结点的指针指向新结点，p为第一个结点 */
        r=p;	/*将当前的新结点定义为表尾终端结点 */
    }
    r->next = NULL;	/*  表示当前链表结束 */

    return OK;
}
/*打印一元多项式P*/
Status PrintPolyn(LinkList P)
{
    LinkList p=P->next; /*p指向第一个结点*/

    while(p->next)
    {
        printf("%dY(%d)+",p->data[0],p->data[1]);
        p=p->next;
    }
    printf("%dY(%d)",p->data[0],p->data[1]);

    printf("\n");

    return OK;
}

/*获取P中元素的系数和指数*/
Status GetElem(LinkList P,int i,ElemType *e1,ElemType *e2)
{
    int j;
    LinkList p;	/*  声明一结点 p */

    p = P->next;	/*  让 p 指向链表 L 的第一个结点 */
    j = 1;	  /*j 为计数器 */

    while (p && j<i)	/* p 不为空或者计数器 j 还没有等于 i 时，循环继续 */
    {
        p = p->next;	/*  让 p 指向下一个结点 */
        ++j;
    }

    if ( !p || j>i )
        return ERROR;	/*	第 i 个元素不存在 */
    *e1 = p->data[0];	/*	取第 i 个元素的系数 */
    *e2 = p->data[1];   /*  取第 i 个元素的指数*/

    return OK;
}

/*寻找与e指数相等的元素位置*/
Status LocateElem(LinkList P,ElemType e)
{
    int i=0;
    LinkList p=P->next;
    while(p)
    {
        i++;
        if(p->data[1]==e) /*  找到这样的数据元素 */
            {
				return i;
				break;
			}

        p=p->next;
    }

    return 0;
}

/*在P中第 i 个位置之前插入新的数据元素e*/
Status ListInsert(LinkList *P,int i,ElemType e1,ElemType e2)
{
    int j;
    LinkList p,s;
    p = *P; /*p为头结点*/
    j = 1;

    while (p && j < i)	/*  寻找第i个结点。此时，p指向的是i的前驱*/
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i)
        return ERROR;	/* 第 i 个元素不存在 */

    s = (LinkList)malloc(sizeof(Node));	/*	生成新结点 */

    s->data[0] = e1;
    s->data[1] = e2;

    s->next = p->next;	/*  将 p 的后继结点赋值给 s 的后继	*/
    p->next = s;	/*  将 s 赋值给 p 的后继 */

    return OK;
}
