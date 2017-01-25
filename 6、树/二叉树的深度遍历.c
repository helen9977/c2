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

/*输出结点*/

void visit(TElemType c,int level)
{
    printf("%c 位于第 %d 层\n",c,level);
}
/*先序访问二叉树*/
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

/*中序访问二叉树*/
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

/*后序访问二叉树*/
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

/*非递归先序遍历*/
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
/*非递归中序遍历*/
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
    printf("请用先序序列输入二叉树：\n");
    CreateBiTree(&T);
    printf("先序遍历结果为：\n");
    PreOrderTraverse(T,level);
    printf("中序遍历结果为：\n");
    InOrderTraverse(T,level);
    printf("后序遍历结果为：\n");
    PostOrderTraverse(T,level);

    return 0;
}
