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

typedef int Status;	    /* Status 是函数的类型,其值是函数结果状态代码 */
typedef int ElemType;	/* ElemType 类型根据实际情况而定*/



typedef struct
{
    ElemType data[MAXSIZE];	 /* 数组，存储数据元素 */
    int length;	 /* 线性表当前长度 */
}SqList;


/*初始化顺序线性表*/

Status InitList(SqList *L)
{
    L->length=0;
    return OK;

}

/*判断L是否为空*/
Status ListEmpty(SqList L)
{
    if(L.length==0)
        return TRUE;

    else
        return FALSE;
}


/*将L重置为空表*/
Status ClearList(SqList *L)
{
    L->length=0;
    return OK;
}

/*返回元素的个数*/
int ListLength(SqList L)
{
    return L.length;
}


/*用e返回L中第i个数据元素的值
注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)/*空表或指定位置不合理*/
        return ERROR;
    *e=L.data[i-1];
    return OK;
}

/* 返回L中第一个与e相等的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为 0 */
int LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0) /*空表*/
        return 0;
    for(i=0;i<L.length;i++)
    {
        if (L.data[i]==e)/*寻找与e相等的元素*/
        break;
    }

	if(i>=L.length) /*没有寻找到与e相等的元素*/
        return 0;
        
        return i+1;/*返回相等元素的位置*/

}

/*前插法*/
/*在L中第i个位置之前插入新的数据元素e*/
Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if (L->length==MAXSIZE)	/* 顺序线性表已经满 */
        return ERROR;
    if  (i<1  ||  i>L->length+1)/*  当 i 比第一位置小或者比最后一位置后一位置还要大时*/
        return ERROR;

    if (i<=L->length)	/*  若插入数据位置不在表尾 */
    {
        for(k=L->length-1;k>=i-1;k--)	/*  将要插入位置之后的数据元素向后移动一位*/
            L->data[k+1]=L->data[k];
    }

    L->data[i-1]=e;	/*  将新元素插入 */
    L->length++;

    return OK;
}

/*删除L的第i个数据元素*/
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if (L->length==0)	/*  线性表为空 */
        return ERROR;
    if (i<1 || i>L->length)	/*  删除位置不正确 */
        return ERROR;

    *e=L->data[i-1];

    if (i<L->length)	/*  如果删除不是最后位置 */
    {
        for(k=i;k<L->length;k++)/*  将删除位置后继元素前移 */
            L->data[k-1]=L->data[k];
    }

    L->length--;

    return OK;
}


/*显示某个元素*/
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/*依次对L的每个数据元素输出*/

Status ListTraverse(SqList L)
{
    int i;

    for(i=0;i<L.length;i++)
        visit(L.data[i]);

    printf("\n");

    return OK;
}
 

