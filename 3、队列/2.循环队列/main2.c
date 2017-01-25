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
typedef int QElemType;/* ElemType ���͸���ʵ������������������Ϊ int */

typedef struct
{
    QElemType base[MAXSIZE];
    int front;
    int rear;
}Queue;

/*��ʼ��ѭ������*/
Status InitQueue(Queue *Q)
{
    Q->front=Q->rear=0;
    return OK;
}
/*��Q�ƿ�*/
Status ClearQueue(Queue *Q)
{
    Q->front=Q->rear=0;
    return OK;
}
/*�ж�Q�Ƿ�Ϊ��*/
Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}
/*����Q�ĳ���*/
Status QueueLength(Queue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
/*�ڶ�β����Ԫ��e*/
Status EnQueue(Queue *Q,QElemType e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
        return ERROR;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
/*ɾ����ͷԪ�أ���e������ֵ*/
Status DeQueue(Queue *Q,QElemType *e)
{
    if(Q->front==Q->rear)
        return ERROR;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}
