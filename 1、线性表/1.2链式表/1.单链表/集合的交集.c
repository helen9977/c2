
#include "main1.c"

int main()
{

    int n,m;
    int i,e;
    LinkList La,Lb;
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

	for (i=1;i<=m;i++)
    {
    	GetElem(Lb,i,&e);

		if (LocateElem(La,e)==0)
    /* 在La中没有找到与Lb相等的元素 */
    /*LocateElem返回非空 , !LocatElem即为空*/
        ListInsert(&La,++n,e);/*在La头部插入新元素*/
    }
    printf("依次输出合并了 Lb 的 La的元素：");
    ListTraverse(La);
    return 0;
}
