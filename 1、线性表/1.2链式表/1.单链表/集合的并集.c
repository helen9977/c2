#include "main1.c"

int main()
{

    int n,m;
    int i,e;
    LinkList La,Lb,Lc;
    printf("请输入La的长度：\n");
    scanf("%d",&n);
    InitList(&La);
    printf("请依次输入La的元素：\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        ListInsert(&La,i,e);
    }
    printf("请输入Lb的长度：\n");
    scanf("%d",&m);
    InitList(&Lb);
    printf("请依次输入Lb的元素：\n");
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

    printf("Lb和La的交集是：");
    ListTraverse(La);

    return 0;

}
