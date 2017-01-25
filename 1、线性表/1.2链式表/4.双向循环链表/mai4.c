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
    struct Node *prior;
    struct Node *next;
}Node;
typedef struct Node* LinkList; /*  定义 LinkList */

Status CreateLinkList(LinkList *L,int n)
{
    LinkList p,q;
    int i,e;
    *L=p=(LinkList)malloc(sizeof(Node)); //生成头结点
    (*L)->next=(*L)->prior=NULL;
    if(!(*L))
        return ERROR;

    p=(*L);
    printf("请输入链表元素：\n");
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

    printf("请输入要建立的链表长度：\n");
    scanf("%d",&n);
    CreateLinkList(&L,n);
    printf("请输入要翻转的位置：\n");
    scanf("%d",&k);
    Find(&L,k);

   printf("翻转后的顺序是：\n");
    for(i=0;i<n;i++)
    {
        L=L->next;
        printf("%d ",L->data);
    }
    return 0;
}
