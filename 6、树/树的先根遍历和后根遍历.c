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
typedef char TElemType;/* ElemType 类型根据实际情况而定 */


typedef struct CSNode	/*  结点结构 */
{
    TElemType data;	/*  结点数据 */
    struct CSTNode *firstchild,*nextsibling; /*  左孩子右兄弟 */
}CSNode,*CSTree;


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
/*先根遍历树*/
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
/*后根遍历树*/
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
