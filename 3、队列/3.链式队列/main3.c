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
    Queueptr front;//��ͷָ��
    Queueptr rear;//��βָ��
}LinkQueue;

/*����һ���ն���*/
Status InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=(Queueptr)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next=NULL;
    return OK;

}

/*��Q��Ϊ�ն���*/
Status ClearQueue(LinkQueue *Q)
{
    Q->rear=Q->front;//rearָ��ͷ
    while(Q->rear)
    {
        Q->front=Q->rear;
        Q->rear=Q->rear->next;
        free(Q->front);
    }
    return OK;
}

/*�ж�Q�Ƿ�Ϊ��*/
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

/*���ض��г���*/
int QueueLength(LinkQueue Q)
{
    return Q.rear-Q.front+1;
}

/*��e���ض�ͷԪ��*/
Status GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front==Q.rear)
        return ERROR;
    *e=Q.front->next->data;
    return OK;
}

/*�ڶ�β����Ԫ��e*/
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
/*�ڶ�ͷɾ��Ԫ�أ�����e������ֵ*/
Status DeQueue (LinkQueue *Q,QElemType *e)
{
    Queueptr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;//ǰָ�����
    if(Q->rear==p)
    	Q->rear=Q->front;
    free(p);//�ͷ�ԭ���Ķ�ͷָ��
    return OK;

}
 /*���ĳ��Ԫ��*/
 Status visit(QElemType c)
{
    printf("%d ",c);

    return OK;
}

/*�������Ԫ��*/
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
