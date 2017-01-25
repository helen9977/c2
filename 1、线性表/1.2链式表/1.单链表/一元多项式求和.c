#include"main1.1.c"

int main()
{
    LinkList P1,P2;
    ElemType e1,e2;
    int i,j,k,b;
    int n,m;
    LinkList p;
    printf("请输入P1的项数：\n");
    scanf("%d",&n);
    printf("请依次输入P1元素的系数和指数：\n");
    CreatPolyn(&P1,n);
    printf("请输入p2的项数：\n");
    scanf("%d",&m);
    printf("请依次输入P2元素的系数和指数：\n");
    CreatPolyn(&P2,m);
    printf("\n一元多项数P1为(括号内表示指数):\n");
    PrintPolyn(P1);
    printf("\n一元多项式P2为(括号内表示指数):\n");
    PrintPolyn(P2);
    for(i=1;i<=n;i++)
    {
        GetElem(P1,i,&e1,&e2);

        if(LocateElem(P2,e2)==0) //p2中没有与p1相等指数的项，把它直接插入p2后

            ListInsert(&P2,++m,e1,e2);
        else
        {
            k=LocateElem(P2,e2);
            p = P2->next;	/*  让 p 指向链表 p2 的第一个结点 */
            b = 1;	  /*b 为计数器 */

            while (p && b<k)	/* p 不为空或者计数器 j 还没有等于 i 时，循环继续 */
            {
                p = p->next;	/*  让 p 指向下一个结点 */
                ++b;
            }

            p->data[0]=p->data[0]+e1;//系数相加
        }

    }
    printf("\nP2与P1求和的结果是：(括号内表示指数)\n");
    PrintPolyn(P2);
    return 0;
}
