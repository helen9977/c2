#include"main1.1.c"

int main()
{
    LinkList P1,P2;
    ElemType e1,e2;
    int i,j,k,b;
    int n,m;
    LinkList p;
    printf("������P1��������\n");
    scanf("%d",&n);
    printf("����������P1Ԫ�ص�ϵ����ָ����\n");
    CreatPolyn(&P1,n);
    printf("������p2��������\n");
    scanf("%d",&m);
    printf("����������P2Ԫ�ص�ϵ����ָ����\n");
    CreatPolyn(&P2,m);
    printf("\nһԪ������P1Ϊ(�����ڱ�ʾָ��):\n");
    PrintPolyn(P1);
    printf("\nһԪ����ʽP2Ϊ(�����ڱ�ʾָ��):\n");
    PrintPolyn(P2);
    for(i=1;i<=n;i++)
    {
        GetElem(P1,i,&e1,&e2);

        if(LocateElem(P2,e2)==0) //p2��û����p1���ָ���������ֱ�Ӳ���p2��

            ListInsert(&P2,++m,e1,e2);
        else
        {
            k=LocateElem(P2,e2);
            p = P2->next;	/*  �� p ָ������ p2 �ĵ�һ����� */
            b = 1;	  /*b Ϊ������ */

            while (p && b<k)	/* p ��Ϊ�ջ��߼����� j ��û�е��� i ʱ��ѭ������ */
            {
                p = p->next;	/*  �� p ָ����һ����� */
                ++b;
            }

            p->data[0]=p->data[0]+e1;//ϵ�����
        }

    }
    printf("\nP2��P1��͵Ľ���ǣ�(�����ڱ�ʾָ��)\n");
    PrintPolyn(P2);
    return 0;
}
