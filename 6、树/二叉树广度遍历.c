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
#define MAXSIZE 100 /*  存储空间初始分配量 */

typedef int Status;/* Status 是函数的类型,其值是函数结果状态代码*/
typedef char TElemType;/* ElemType 类型根据实际情况而定 */


typedef struct BiTNode	/*  结点结构 */
{
    TElemType data;	/*  结点数据 */
    struct BiTNode *lchild,*rchild; /*  左右孩子指针 */
}BiTNode,*BiTree;

/*前序建立二叉链表*/
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
        (*T)->data = c;//生成根结点
        CreateBiTree(&(*T)->lchild);//递归生成左子结点
        CreateBiTree(&(*T)->rchild);//递归生成右子结点
    }
    return OK;
}
/*广度遍历二叉树*/
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
