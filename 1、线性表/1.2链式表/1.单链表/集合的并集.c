#include "main1.c"

int main()
{

    int n,m;
    int i,e;
    LinkList La,Lb,Lc;
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
    InitList(&Lc);
    for (i=1;i<=m;i++)
    {
    	GetElem(Lb,i,&e);
    	if (LocateElem(La,e))

        ListInsert(&Lc,1,e);
    }

    printf("Lb��La�Ľ����ǣ�");
    ListTraverse(La);

    return 0;

}
