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

#define MAXSIZE 100 /*  存储空间初始分配量 */

typedef int Status;/* Status 是函数的类型,其值是函数结果状态代码*/
typedef int ElemType;/* ElemType 类型根据实际情况而定，这里假设为 int */

typedef struct
{
    ElemType data[MAXSIZE];	 /* 数组，存储数据元素 */
    int front;
    int rear;
}Queue;

/*初始化队列*/
Status InitQueue(Queue *Q)
{
    Q->front=Q->rear=-1;
    return OK;
}

/*判断Q是否为空*/

Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear==-1)
        return TRUE;
    else
        return FALSE;
}

/*将Q置为空*/
Status ClearQueue (Queue *Q)
{
    Q->front=Q->rear=-1;
    return OK;
}
/*返回长度*/
Status QueueLength (Queue Q)
{
    return Q.rear-Q.front+1;
}

/*返回队头元素*/
Status GetHead(Queue Q,ElemType *e)
{
    if(Q.front==Q.rear==1)
        return ERROR;
    Q.front++; 
    *e=Q.data[Q.front];
    return OK;
}

/*在队尾插入新的元素e*/
Status EnQueue (Queue *Q,ElemType e)
{
	if(Q->rear==MAXSIZE-1)
	return ERROR;
	Q->rear++;
	Q->data[Q->rear]=e;
	return OK;
} 

/*删除队头元素，用e返回其值*/
Status DeQueue (Queue *Q,ElemType *e)
{
	if(Q->front==Q->rear==-1)
	return ERROR;
	Q->front++;
	*e=Q->data[Q->front];
	
	return OK; 
}

/*输出队列里的元素*/
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}


/*依次显示出元素*/
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
