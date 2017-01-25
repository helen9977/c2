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
typedef int QElemType;/* ElemType 类型根据实际情况而定，这里假设为 int */

typedef struct
{
    QElemType base[MAXSIZE];
    int front;
    int rear;
}Queue;

/*初始化循环队列*/
Status InitQueue(Queue *Q)
{
    Q->front=Q->rear=0;
    return OK;
}
/*将Q制空*/
Status ClearQueue(Queue *Q)
{
    Q->front=Q->rear=0;
    return OK;
}
/*判断Q是否为空*/
Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}
/*返回Q的长度*/
Status QueueLength(Queue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
/*在队尾插入元素e*/
Status EnQueue(Queue *Q,QElemType e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
        return ERROR;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
/*删除队头元素，用e返回其值*/
Status DeQueue(Queue *Q,QElemType *e)
{
    if(Q->front==Q->rear)
        return ERROR;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}
