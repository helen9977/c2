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
    ElemType data[2];
    struct Node *next;
}Node;
typedef struct Node* LinkList; /*  ���� LinkList */

/*����һԪ����ʽP*/
Status CreatPolyn(LinkList *P,int m)
{
    *P=(LinkList)malloc(sizeof(Node)); /*  ����ͷ��� */
    if(!(*P)) /*  �洢����ʧ�� */
        return ERROR;
    (*P)->next=NULL; /*  ָ����Ϊ�� */

    LinkList p,r;
    int i;
    r=*P;	/* rΪָ��β���Ľ�� */
    for (i=0; i<m; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*�����½�� */
        scanf("%d",&p->data[0]);
        scanf("%d",&p->data[1]);
        r->next=p;	/*����β�ն˽���ָ��ָ���½�㣬pΪ��һ����� */
        r=p;	/*����ǰ���½�㶨��Ϊ��β�ն˽�� */
    }
    r->next = NULL;	/*  ��ʾ��ǰ������� */

    return OK;
}
/*��ӡһԪ����ʽP*/
Status PrintPolyn(LinkList P)
{
    LinkList p=P->next; /*pָ���һ�����*/

    while(p->next)
    {
        printf("%dY(%d)+",p->data[0],p->data[1]);
        p=p->next;
    }
    printf("%dY(%d)",p->data[0],p->data[1]);

    printf("\n");

    return OK;
}

/*��ȡP��Ԫ�ص�ϵ����ָ��*/
Status GetElem(LinkList P,int i,ElemType *e1,ElemType *e2)
{
    int j;
    LinkList p;	/*  ����һ��� p */

    p = P->next;	/*  �� p ָ������ L �ĵ�һ����� */
    j = 1;	  /*j Ϊ������ */

    while (p && j<i)	/* p ��Ϊ�ջ��߼����� j ��û�е��� i ʱ��ѭ������ */
    {
        p = p->next;	/*  �� p ָ����һ����� */
        ++j;
    }

    if ( !p || j>i )
        return ERROR;	/*	�� i ��Ԫ�ز����� */
    *e1 = p->data[0];	/*	ȡ�� i ��Ԫ�ص�ϵ�� */
    *e2 = p->data[1];   /*  ȡ�� i ��Ԫ�ص�ָ��*/

    return OK;
}

/*Ѱ����eָ����ȵ�Ԫ��λ��*/
Status LocateElem(LinkList P,ElemType e)
{
    int i=0;
    LinkList p=P->next;
    while(p)
    {
        i++;
        if(p->data[1]==e) /*  �ҵ�����������Ԫ�� */
            {
				return i;
				break;
			}

        p=p->next;
    }

    return 0;
}

/*��P�е� i ��λ��֮ǰ�����µ�����Ԫ��e*/
Status ListInsert(LinkList *P,int i,ElemType e1,ElemType e2)
{
    int j;
    LinkList p,s;
    p = *P; /*pΪͷ���*/
    j = 1;

    while (p && j < i)	/*  Ѱ�ҵ�i����㡣��ʱ��pָ�����i��ǰ��*/
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i)
        return ERROR;	/* �� i ��Ԫ�ز����� */

    s = (LinkList)malloc(sizeof(Node));	/*	�����½�� */

    s->data[0] = e1;
    s->data[1] = e2;

    s->next = p->next;	/*  �� p �ĺ�̽�㸳ֵ�� s �ĺ��	*/
    p->next = s;	/*  �� s ��ֵ�� p �ĺ�� */

    return OK;
}
