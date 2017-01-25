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

typedef struct Node* LinkList;

/*����ѭ������*/
Status CreateLinklist(LinkList *head,int n)
{
    LinkList p,q;
    int i=1;
    *head=p=(LinkList)malloc(sizeof(Node));//ͷָ��ָ���һ�����
    p->data=i;
    for(i=2;i<=n;i++)
    {
        q=(LinkList)malloc(sizeof(Node));
        if(!q) return(ERROR);
        p->next=q;
        p=q;
        p->data=i;
    }
    p->next=*head;          /*ʹ����βָ������ͷ �γ�ѭ������*/

    return OK;
}

/*��ʾ��������*/
Status PrintLinklist(LinkList *p,int n)
{
    int i;
    LinkList q = *p;
    if(q->next == NULL)
    {
        printf("the list is NULL!");
        return OK;
    }
    for(i=1;i<=n;i++)
    {
    if(q == NULL)
    {
        printf("the list is NULL!");
        return;
    }
        printf("%d  ",q->data);
        q=q->next;
    }
    printf("\n");
    return OK;
}

/*Լɪ�򻷺���*/ 
Status joseph(LinkList p,int n,int k,int m)
{
    int i,j;
    LinkList q;
    
    for(i=1;i<k;i++)
    {
    	p=p->next; //�ҵ���ʼλ�� 
	}
	
    for(i=1;i<n;i++)
    {
        for(j=1;j<m-1;j++)
        {
            p=p->next;
        }
        
        q=p->next;
        p->next = q->next;//ɾ��q��� 
        printf("%d  ",q->data);
        free(q);
    }
    printf("\n���ʣ����ǵ�%d��.\n",p->data);
    p->next=NULL;
    return OK;
}

