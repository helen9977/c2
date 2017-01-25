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

#define MAXSIZE 100 /*  �洢�ռ��ʼ������ */

typedef int Status;/* Status �Ǻ���������,��ֵ�Ǻ������״̬����*/
typedef int ElemType;/* ElemType ���͸���ʵ������������������Ϊ int */

typedef struct
{
    ElemType data[MAXSIZE];	 /* ���飬�洢����Ԫ�� */
    int front;
    int rear;
}Queue;

/*��ʼ������*/
Status InitQueue(Queue *Q)
{
    Q->front=Q->rear=-1;
    return OK;
}

/*�ж�Q�Ƿ�Ϊ��*/

Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear==-1)
        return TRUE;
    else
        return FALSE;
}

/*��Q��Ϊ��*/
Status ClearQueue (Queue *Q)
{
    Q->front=Q->rear=-1;
    return OK;
}
/*���س���*/
Status QueueLength (Queue Q)
{
    return Q.rear-Q.front+1;
}

/*���ض�ͷԪ��*/
Status GetHead(Queue Q,ElemType *e)
{
    if(Q.front==Q.rear==1)
        return ERROR;
    Q.front++; 
    *e=Q.data[Q.front];
    return OK;
}

/*�ڶ�β�����µ�Ԫ��e*/
Status EnQueue (Queue *Q,ElemType e)
{
	if(Q->rear==MAXSIZE-1)
	return ERROR;
	Q->rear++;
	Q->data[Q->rear]=e;
	return OK;
} 

/*ɾ����ͷԪ�أ���e������ֵ*/
Status DeQueue (Queue *Q,ElemType *e)
{
	if(Q->front==Q->rear==-1)
	return ERROR;
	Q->front++;
	*e=Q->data[Q->front];
	
	return OK; 
}

/*����������Ԫ��*/
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}


/*������ʾ��Ԫ��*/
Status StackTraverse(Queue Q)
{
    int i;
    i=0;

    while(i<=Q.rear)
    {
        visit(Q.data[i++]);
    }

    printf("\n");
    return OK;
}
