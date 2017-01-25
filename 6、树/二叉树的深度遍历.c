#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
//#include "main.c"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*  �洢�ռ��ʼ������ */

typedef int Status;/* Status �Ǻ���������,��ֵ�Ǻ������״̬����*/
typedef char TElemType;/* ElemType ���͸���ʵ��������� */


typedef struct BiTNode	/*  ���ṹ */
{
    TElemType data;	/*  ������� */
    struct BiTNode *lchild,*rchild; /*  ���Һ���ָ�� */
}BiTNode,*BiTree;

/*ǰ������������*/
Status CreateBiTree(BiTree *T)
{
    TElemType c;
    scanf("%c",&c);
    if(c==' ')
        *T=NULL;
    else
    {
        *T=(BiTNode *)malloc(sizeof(BiTNode));
        if(!(*T))
            return ERROR;
        (*T)->data = c;//���ɸ����
        CreateBiTree(&(*T)->lchild);//�ݹ��������ӽ��
        CreateBiTree(&(*T)->rchild);//�ݹ��������ӽ��
    }
    return OK;
}

/*������*/

void visit(TElemType c,int level)
{
    printf("%c λ�ڵ� %d ��\n",c,level);
}
/*������ʶ�����*/
Status PreOrderTraverse(BiTree T,int level)
{
    if(T)
    {
        visit(T->data,level);
        PreOrderTraverse(T->lchild,level+1);
        PreOrderTraverse(T->rchild,level+1);

    }

    return OK;
}

/*������ʶ�����*/
Status InOrderTraverse(BiTree T,int level)
{
    if(T)
    {
        PreOrderTraverse(T->lchild,level+1);
        visit(T->data,level);
        PreOrderTraverse(T->rchild,level+1);

    }

    return OK;
}

/*������ʶ�����*/
Status PostOrderTraverse(BiTree T,int level)
{
    if(T)
    {
        PreOrderTraverse(T->lchild,level+1);
        PreOrderTraverse(T->rchild,level+1);
        visit(T->data,level);

    }

    return OK;
}

/*�ǵݹ��������*/
/*
Status preTraverse(BiTree T,int level)
{
    SqStack S;
    InitStack(S);
    if(!T)
        return ERROR;
    Push(&S,T);
    while(!StackEmpty(S))
    {
        Pop(&S,&T);
        visit(T,level);
        if(T->rchild!=NULL)
            Push(&S,T->rchild);
        if(T->lchild!==NULL)
            Push(&S,T->lchild);
    }
    return OK;
}
*/
/*�ǵݹ��������*/
/*
Status preTraverse(BiTree T,int level)
{
    SqStack S;
    InitStack(S);
    if(!T)
        return ERROR;
    Push(&S,T);
    while(!StackEmpty(S))
    {
        Pop(&S,&T);
        if(T->rchild!=NULL)
            Push(&S,T->rchild);
        visit(T,level);
        if(T->lchild!==NULL)
            Push(&S,T->lchild);
    }
    return OK;
}
*/
int main()
{
    int level =1;
    BiTree T=NULL;
    printf("�����������������������\n");
    CreateBiTree(&T);
    printf("����������Ϊ��\n");
    PreOrderTraverse(T,level);
    printf("����������Ϊ��\n");
    InOrderTraverse(T,level);
    printf("����������Ϊ��\n");
    PostOrderTraverse(T,level);

    return 0;
}
