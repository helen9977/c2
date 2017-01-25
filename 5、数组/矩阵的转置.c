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

#define MAXSIZE 12500 /*  存储空间初始分配量 */

typedef int Status;/* Status 是函数的类型,其值是函数结果状态代码*/
typedef int ElemType;/* ElemType 类型根据实际情况而定，这里假设为 int */


typedef struct
{
    int i,j;
    ElemType e;
}Triple;//三元序列
typedef struct
{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;
}TSMatrix;

Status TranspeseSMatrix(TSMatrix M,TSMatrix *T)
{
    int col,t,i,j,p,q;
    int num[MAXSIZE],cpot[MAXSIZE];
    T->mu=M.nu;
    T->nu=M.mu;
    //行列对换
    T->tu=M.tu;//非零个数不变
    if(T->tu)
    {
        for(col=1;col<=M.nu;++col)
            num[col]=0;//初始化，每列为0
        for(t=1;t<M.nu;++t)
            ++num[M.data[t].j];//记录每列非零元的个数
        cpot[1]=1;//初始化第一列在新矩阵中的第一个行
        for(col=2;col<M.nu;++col)
            cpot[col]=cpot[col-1]+num[col-1];//在新矩阵中的data[i]的i位置
        for(p=1;p<=M.tu;++p)
        {
            col=M.data[p].j;//从头遍历J
            q=cpot[col];//q是第col列在新矩阵的相对位置
            T->data[q].i=M.data[p].j;
            T->data[q].j=M.data[p].i;
            T->data[q].e=M.data[p].e;
            ++cpot[col];//此位置被占，向后推一个位置等待下一个元素
        }
    }
    return OK;
}

int main()
{
    int k;
    TSMatrix M,T;
    printf("请输入M矩阵的大小和非零元素个数：\n");
    scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
    printf("请输入M矩阵的稀疏矩阵：\n");
    for(k=1;k<=M.tu;k++)
    {
        scanf("%d%d%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
    }
    TranspeseSMatrix(M,&T);
    printf("M矩阵转置后的稀疏矩阵T：\n");

    for(k=1;k<=M.tu;k++)
    {
        printf("第%d行\t第%d列\t元素是%d\n",T.data[k].i,T.data[k].j,T.data[k].e);
    }
    return 0;
}
