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
    struct Node *prior;
    struct Node *next;
}Node;
typedef struct Node* LinkList; /*  ���� LinkList */

Status CreateLinkList(LinkList *L,int n)
{
    LinkList p,q;
    int i,e;
    *L=p=(LinkList)malloc(sizeof(Node)); //����ͷ���
    (*L)->next=(*L)->prior=NULL;
    if(!(*L))
        return ERROR;

    p=(*L);
    printf("����������Ԫ�أ�\n");
    for(i=0;i<n;i++)
    {

        q=(LinkList)malloc(sizeof(Node));
        if(!q)
            return ERROR;
        scanf("%d",&e);
        q->data=e;
        q->prior=p;
        q->next=p->next;
        p->next=q;

        p=q;
    }
    p->next=(*L)->next;
    (*L)->next->prior=p;

    return OK;
}

Status Find(LinkList *L,int i)
{
    if(i>0)
    {
        do
        {
        *L=(*L)->next;
        }while(--i);
    }
     if(i<0)
    {
        do
        {
        *L=(*L)->next;
        }while(++i);
    }

    return OK;
}


int main()
{
    LinkList L;
    int i,n,k;

    printf("������Ҫ�����������ȣ�\n");
    scanf("%d",&n);
    CreateLinkList(&L,n);
    printf("������Ҫ��ת��λ�ã�\n");
    scanf("%d",&k);
    Find(&L,k);

   printf("��ת���˳���ǣ�\n");
    for(i=0;i<n;i++)
    {
        L=L->next;
        printf("%d ",L->data);
    }
    return 0;
}
