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

#define MAXSIZE 12500 /*  �洢�ռ��ʼ������ */

typedef int Status;/* Status �Ǻ���������,��ֵ�Ǻ������״̬����*/
typedef int ElemType;/* ElemType ���͸���ʵ������������������Ϊ int */


typedef struct
{
    int i,j;
    ElemType e;
}Triple;//��Ԫ����
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
    //���жԻ�
    T->tu=M.tu;//�����������
    if(T->tu)
    {
        for(col=1;col<=M.nu;++col)
            num[col]=0;//��ʼ����ÿ��Ϊ0
        for(t=1;t<M.nu;++t)
            ++num[M.data[t].j];//��¼ÿ�з���Ԫ�ĸ���
        cpot[1]=1;//��ʼ����һ�����¾����еĵ�һ����
        for(col=2;col<M.nu;++col)
            cpot[col]=cpot[col-1]+num[col-1];//���¾����е�data[i]��iλ��
        for(p=1;p<=M.tu;++p)
        {
            col=M.data[p].j;//��ͷ����J
            q=cpot[col];//q�ǵ�col�����¾�������λ��
            T->data[q].i=M.data[p].j;
            T->data[q].j=M.data[p].i;
            T->data[q].e=M.data[p].e;
            ++cpot[col];//��λ�ñ�ռ�������һ��λ�õȴ���һ��Ԫ��
        }
    }
    return OK;
}

int main()
{
    int k;
    TSMatrix M,T;
    printf("������M����Ĵ�С�ͷ���Ԫ�ظ�����\n");
    scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
    printf("������M�����ϡ�����\n");
    for(k=1;k<=M.tu;k++)
    {
        scanf("%d%d%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
    }
    TranspeseSMatrix(M,&T);
    printf("M����ת�ú��ϡ�����T��\n");

    for(k=1;k<=M.tu;k++)
    {
        printf("��%d��\t��%d��\tԪ����%d\n",T.data[k].i,T.data[k].j,T.data[k].e);
    }
    return 0;
}
