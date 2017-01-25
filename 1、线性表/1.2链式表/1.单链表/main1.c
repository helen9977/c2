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

#define MAXSIZE 20 /*  �洢�ռ��ʼ������ */

typedef int Status;/* Status �Ǻ���������,��ֵ�Ǻ������״̬����*/
typedef int ElemType;/* ElemType ���͸���ʵ������������������Ϊ int */



typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node* LinkList; /*  ���� LinkList */


/*��ʼ��˳�����Ա�*/
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node)); /*  ����ͷ��� */
    if(!(*L)) /*  �洢����ʧ�� */
        return ERROR;
    (*L)->next=NULL; /*  ָ����Ϊ�� */

    return OK;
}
/*�ж�L�Ƿ�ձ�*/
Status ListEmpty(LinkList L)
{
    if(L->next)
        return FALSE;

    else
        return TRUE;
}

/*��L����Ϊ�ձ� */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;	/*pָ���һ����� */

    while(p)	/*	û����β */
    {
        q=p->next; /*qָ��p����һ�����*/
        free(p);
        p=q;
    }
    (*L)->next=NULL;	/*  ͷ���ָ����Ϊ�� */

    return OK;
}

/*L������Ԫ�ظ���*/
Status ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* pָ���һ����� */

    while(p)
    {
        i++;
        p=p->next;
    }

    return i;
}


/*L�е�i������Ԫ�ص�ֵ*/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;	/*  ����һ��� p */

    p = L->next;	/*  �� p ָ������ L �ĵ�һ����� */
    j = 1;	  /*j Ϊ������ */

    while (p && j<i)	/* p ��Ϊ�ջ��߼����� j ��û�е��� i ʱ��ѭ������ */
    {
        p = p->next;	/*  �� p ָ����һ����� */
        ++j;
    }

    if ( !p || j>i )
        return ERROR;	/*	�� i ��Ԫ�ز����� */
    *e = p->data;	/*	ȡ�� i ��Ԫ�ص����� */

    return OK;
}


/*����L�е� 1 ����e��ȵ�����Ԫ�ص�λ��*/
Status LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /*  �ҵ�����������Ԫ�� */
            {
				return i;
				break;
			} 
            
        p=p->next;
    }

    return 0;
}


/*��L�е� i ��λ��֮ǰ�����µ�����Ԫ��e*/
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p = *L; /*pΪͷ���*/
    j = 1;

    while (p && j < i)	/*  Ѱ�ҵ�i����㡣��ʱ��pָ�����i��ǰ��*/
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i)
        return ERROR;	/* �� i ��Ԫ�ز����� */

    s = (LinkList)malloc(sizeof(Node));	/*	�����½�� */

    s->data = e;

    s->next = p->next;	/*  �� p �ĺ�̽�㸳ֵ�� s �ĺ��	*/
    p->next = s;	/*  �� s ��ֵ�� p �ĺ�� */

    return OK;
}

/*ɾ��L�ĵ�i������Ԫ��*/
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int j;

    LinkList p,q;
    p = *L; /*pΪͷ���*/
    j = 1;

    while (p->next && j < i)  /*  ����Ѱ�ҵ�i��Ԫ�ء���ʱ��pָ��i��ǰ��*/
    {
        p = p->next;
        ++j;
    }

    if (!(p->next) || j > i)
        return ERROR;	/*  �� i ��Ԫ�ز����� */

    q = p->next;
    p->next = q->next;	/*  �� q �ĺ�̸�ֵ�� p �ĺ�� */

    *e = q->data;	/*  �� q ����е����ݸ� e */
    free(q);	/*  ��ϵͳ���մ˽�㣬�ͷ��ڴ� */

    return OK;
}

/*��ʾĳ������*/
Status visit (ElemType c)
{
    printf("%d ",c);
    return OK;
}

/*�����ζ�L��ÿ������Ԫ����� */

Status ListTraverse(LinkList L)
{
    LinkList p=L->next; /*pָ���һ�����*/

    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");

    return OK;
}


/*	������� n ��Ԫ�ص�ֵ����������ͷ���ĵ������Ա� L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));	/*  ��ʼ����������� */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;	/*	�Ƚ���һ����ͷ���ĵ����� */
    for (i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*	�����½�� */
        p->data = rand()%100+1;	/*	������� 100 ���ڵ����� */
        p->next = (*L)->next;

        (*L)->next = p;	/*	���뵽��ͷ */
    }
}


/*	������� n ��Ԫ�ص�ֵ����������ͷ���ĵ������Ա� L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    srand(time(0));	/* ��ʼ����������� */
    *L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա��ͷ��� */
    r=*L;	/* rΪָ��β���Ľ�� */
    for (i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*�����½�� */
        p->data = rand()%100+1;	/*������� 100 ���ڵ����� */

        r->next=p;	/*����β�ն˽���ָ��ָ���½�㣬pΪ��һ����� */
        r=p;	/*����ǰ���½�㶨��Ϊ��β�ն˽�� */
    }
    r->next = NULL;	/*  ��ʾ��ǰ������� */
}



