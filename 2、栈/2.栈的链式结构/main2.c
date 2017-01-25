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

/*  ��ջ�ṹ */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
    LinkStackPtr top;//top��ָ��ṹ��StackNode��ָ��
    int count; //count�Ǽ�¼ջ�ĳ��� 
}LinkStack;

/*	����һ����ջ S */
Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode)); //topָ��ջ�� 

    if(!S->top)
        return ERROR;

    S->top=NULL;
    S->count=0;

    return OK;
}

/*  �� S ��Ϊ��ջ */
Status ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p=S->top;//ָ��ջ�� 

    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }

    S->count=0;

    return OK;
}
/*  ��ջ S Ϊ��ջ���򷵻� TRUE�����򷵻� FALSE */
Status StackEmpty(LinkStack S)
{
    if (S.count==0)
        return TRUE;
    else
        return FALSE;
}

/*  ���� S ��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(LinkStack S)
{
    return S.count;
}

/*  ��ջ���գ����� e ���� S ��ջ��Ԫ�أ������� OK�����򷵻� ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
    if (S.top==NULL)
        return ERROR;
    else
        *e=S.top->data;

    return OK;
}


/*  ����Ԫ�� e Ϊ�µ�ջ��Ԫ�� */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;	/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�� */
    S->top=s;	 /* ���µĽ�� s ��ֵ��ջ��ָ�� */
    S->count++;

    return OK;
}
/*  ��ջ���գ���ɾ�� S ��ջ��Ԫ�أ��� e ������ֵ�������� OK�����򷵻� ERROR */
Status Pop(LinkStack *S,SElemType *e)
{
    LinkStackPtr p;

    if(StackEmpty(*S))
        return ERROR;

    *e=S->top->data;
    p=S->top;	/*  ��ջ����㸳ֵ�� p */
    S->top=S->top->next;	/*  ʹ��ջ��ָ������һλ��ָ���һ���*/
    free(p);	/*  �ͷŽ�� pɾ��ջ��Ԫ��*/
    S->count--;

    return OK;
}

 /*���ĳ��Ԫ��*/
 Status visit(SElemType c)
{
    printf("%d ",c);

    return OK;
}

/*��ջ����ջ���������Ԫ��*/
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
