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

typedef struct Node* LinkList;

/*生成循环链表*/
Status CreateLinklist(LinkList *head,int n)
{
    LinkList p,q;
    int i=1;
    *head=p=(LinkList)malloc(sizeof(Node));//头指针指向第一个结点
    p->data=i;
    for(i=2;i<=n;i++)
    {
        q=(LinkList)malloc(sizeof(Node));
        if(!q) return(ERROR);
        p->next=q;
        p=q;
        p->data=i;
    }
    p->next=*head;          /*使链表尾指向链表头 形成循环链表*/

    return OK;
}

/*显示链表数据*/
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

/*约瑟夫环函数*/ 
Status joseph(LinkList p,int n,int k,int m)
{
    int i,j;
    LinkList q;
    
    for(i=1;i<k;i++)
    {
    	p=p->next; //找到起始位置 
	}
	
    for(i=1;i<n;i++)
    {
        for(j=1;j<m-1;j++)
        {
            p=p->next;
        }
        
        q=p->next;
        p->next = q->next;//删除q结点 
        printf("%d  ",q->data);
        free(q);
    }
    printf("\n最后剩余的是第%d号.\n",p->data);
    p->next=NULL;
    return OK;
}

