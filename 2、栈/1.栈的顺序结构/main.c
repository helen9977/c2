#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
#define MAXINCREMENT 10

typedef  double SElemType;
typedef  int Status;

typedef struct
{
    SElemType data[MAXSIZE];
    int top; /*  ����ջ��ָ�� */
}SqStack;


/*	����һ����ջ S */
Status InitStack(SqStack *S)
{
    S->top=-1;
    return OK;
}
/*  �� S ��Ϊ��ջ */
Status ClearStack(SqStack *S)
{
    S->top=-1;
    return OK;
}
/*  ��ջ S Ϊ��ջ���򷵻� TRUE�����򷵻� FALSE */
Status StackEmpty(SqStack S)
{
    if (S.top==-1)
        return TRUE;

    else
        return FALSE;

}
/*  ���� S ��Ԫ�ظ�������ջ�ĳ��� */
Status StackLength(SqStack S)
{
    return S.top+1;
}
/*  ��ջ���գ����� e ���� S ��ջ��Ԫ�أ������� OK�����򷵻� ERROR */
SElemType GetTop(SqStack S)
{
	SElemType e;
    if (S.top==-1)
    {
    	printf("\n\a������\n\n");
    	exit(1);
	}
    else
        e=S.data[S.top];
    return e;
}

/*  ����Ԫ�� e Ϊ�µ�ջ��Ԫ�� */
Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE -1) /*  ջ�� */
{
    return ERROR;
}
    S->top++;	/*  ջ��ָ������һ */
    S->data[S->top]=e;	/*  ���²���Ԫ�ظ�ֵ��ջ���ռ� */
    return OK;
}

/*  ��ջ���գ���ɾ�� S ��ջ��Ԫ�أ��� e ������ֵ�������� OK�����򷵻� ERROR */
Status Pop(SqStack *S,SElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];	/*  ��Ҫɾ����ջ��Ԫ�ظ�ֵ�� e */
    S->top--;	/*  ջ��ָ���һ */
    return OK;
}

/*���ջ���Ԫ��*/
Status visit(SElemType c)
{
    printf("%lf ",c);
    return OK;
}


/*��ջ��������ʾ��Ԫ��*/
Status StackTraverse(SqStack S)
{
    int i;
    i=0;

    while(i<=S.top)
    {
        visit(S.data[i++]);
    }

    printf("\n");
    return OK;
}


/*
int main()
{
    int j;
    SqStack s;
    int e;

    if(InitStack(&s)==OK)

    for(j=1;j<=10;j++)
        Push(&s,j);
    printf("ջ��Ԫ������Ϊ��");
    StackTraverse(s);

    Pop(&s,&e);
    printf("������ջ��Ԫ�� e=%d\n",e);

    printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));

    GetTop(s,&e);
    printf("ջ��Ԫ�� e=%d  ջ�ĳ���Ϊ%d\n",e,StackLength(s));

    ClearStack(&s);
    printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));

    return 0;

}
*/

