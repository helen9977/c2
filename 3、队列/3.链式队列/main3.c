#include <stdio.h>
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

#define MAXSIZE 100
#define MAXINCREMENT 10

typedef  int QElemType;
typedef  int Status;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*Queueptr;

typedef struct
{
    Queueptr front;//队头指针
    Queueptr rear;//队尾指针
}LinkQueue;

/*构造一个空队列*/
Status InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=(Queueptr)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next=NULL;
    return OK;

}

/*将Q清为空队列*/
Status ClearQueue(LinkQueue *Q)
{
    Q->rear=Q->front;//rear指向头
    while(Q->rear)
    {
        Q->front=Q->rear;
        Q->rear=Q->rear->next;
        free(Q->front);
    }
    return OK;
}

/*判断Q是否为空*/
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

/*返回队列长度*/
int QueueLength(LinkQueue Q)
{
    return Q.rear-Q.front+1;
}

/*用e返回队头元素*/
Status GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front==Q.rear)
        return ERROR;
    *e=Q.front->next->data;
    return OK;
}

/*在队尾插入元素e*/
Status EnQueue(LinkQueue *Q,QElemType e)
{
    Queueptr s;
    s=(Queueptr)malloc(sizeof(QNode));
    if(!s)
        return ERROR;
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;

    return OK;
}
/*在队头删除元素，并用e返回其值*/
Status DeQueue (LinkQueue *Q,QElemType *e)
{
    Queueptr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;//前指针后移
    if(Q->rear==p)
    	Q->rear=Q->front;
    free(p);//释放原来的队头指针
    return OK;

}
 /*输出某个元素*/
 Status visit(QElemType c)
{
    printf("%d ",c);

    return OK;
}

/*依次输出元素*/
 Status QueueTraverse(LinkQueue Q)
{
    Queueptr p;
    p=Q.front;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }

    printf("\n");

    return OK;
}
