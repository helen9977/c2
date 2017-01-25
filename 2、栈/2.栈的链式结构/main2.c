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

typedef  int SElemType;
typedef  int Status;

/*  链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
    LinkStackPtr top;//top是指向结构体StackNode的指针
    int count; //count是记录栈的长度 
}LinkStack;

/*	构造一个空栈 S */
Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode)); //top指向栈顶 

    if(!S->top)
        return ERROR;

    S->top=NULL;
    S->count=0;

    return OK;
}

/*  把 S 置为空栈 */
Status ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p=S->top;//指向栈顶 

    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }

    S->count=0;

    return OK;
}
/*  若栈 S 为空栈，则返回 TRUE，否则返回 FALSE */
Status StackEmpty(LinkStack S)
{
    if (S.count==0)
        return TRUE;
    else
        return FALSE;
}

/*  返回 S 的元素个数，即栈的长度 */
int StackLength(LinkStack S)
{
    return S.count;
}

/*  若栈不空，则用 e 返回 S 的栈顶元素，并返回 OK；否则返回 ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
    if (S.top==NULL)
        return ERROR;
    else
        *e=S.top->data;

    return OK;
}


/*  插入元素 e 为新的栈顶元素 */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;	/* 把当前的栈顶元素赋值给新结点的直接后继 */
    S->top=s;	 /* 将新的结点 s 赋值给栈顶指针 */
    S->count++;

    return OK;
}
/*  若栈不空，则删除 S 的栈顶元素，用 e 返回其值，并返回 OK；否则返回 ERROR */
Status Pop(LinkStack *S,SElemType *e)
{
    LinkStackPtr p;

    if(StackEmpty(*S))
        return ERROR;

    *e=S->top->data;
    p=S->top;	/*  将栈顶结点赋值给 p */
    S->top=S->top->next;	/*  使得栈顶指针下移一位，指向后一结点*/
    free(p);	/*  释放结点 p删除栈顶元素*/
    S->count--;

    return OK;
}

 /*输出某个元素*/
 Status visit(SElemType c)
{
    printf("%d ",c);

    return OK;
}

/*从栈顶向栈底依次输出元素*/
 Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p=S.top;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }

    printf("\n");

    return OK;
}
