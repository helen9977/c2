
#include "main1.c"

int main()
{

    int n,m;
    int i,e;
    LinkList La,Lb;
    printf("������La�ĳ��ȣ�\n");
    scanf("%d",&n);
    InitList(&La);
    printf("����������La��Ԫ�أ�\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        ListInsert(&La,i,e);
    }
    printf("������Lb�ĳ��ȣ�\n");
    scanf("%d",&m);
    InitList(&Lb);
    printf("����������Lb��Ԫ�أ�\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d",&e);
        ListInsert(&Lb,i,e);
    }

	for (i=1;i<=m;i++)
    {
    	GetElem(Lb,i,&e);

		if (LocateElem(La,e)==0)
    /* ��La��û���ҵ���Lb��ȵ�Ԫ�� */
    /*LocateElem���طǿ� , !LocatElem��Ϊ��*/
        ListInsert(&La,++n,e);/*��Laͷ��������Ԫ��*/
    }
    printf("��������ϲ��� Lb �� La��Ԫ�أ�");
    ListTraverse(La);
    return 0;
}
