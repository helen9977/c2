#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include "main3.c"

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
/*��ȱ���������*/
Status DepthTraverse (BiTree T,int level)
{
    QElemType e;
    LinkQueue Q;

    if(T)
    {
        InitQueue(&Q);
        EnQueue(&Q,T->data);
       while(Q)
       {
            DeQueue(&Q,&e);
            printf("%c ",e);
            if(T->lchild)
                EnQueue(&Q,T->lchild);
            if(T->rchild)
                EnQueue(&Q,T->rchild);

       }
       printf("\n");

    }
    return OK;
}
