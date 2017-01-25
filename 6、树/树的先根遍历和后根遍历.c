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
typedef char TElemType;/* ElemType ���͸���ʵ��������� */


typedef struct CSNode	/*  ���ṹ */
{
    TElemType data;	/*  ������� */
    struct CSTNode *firstchild,*nextsibling; /*  �������ֵ� */
}CSNode,*CSTree;


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
/*�ȸ�������*/
Status PreOrderTraverse(CSTree T,int level)
{
    if(T)
    {
        visit(T->data,level);
        PreOrderTraverse(T->firstchild,level+1);
        PreOrderTraverse(T->nextsibling,level+1);

    }

    return OK;
}
/*���������*/
Status PostOrderTraverse(CSTree T,int level)
{
    if(T)
    {
        PostOrderTraverse(T->firstchild,level+1);
        visit(T->data,level);
        PostOrderTraverse(T->nextsibling,level+1);

    }

    return OK;
}
