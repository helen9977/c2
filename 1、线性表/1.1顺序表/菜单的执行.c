/*int main()
{

     SqList L;//建立一个线性表
     ElemType e,m;//插入元素，插入元素的最大值
     int k;//插入或删除的位置
     int c;//用于读入选项；
     Status i;//接收返回值
     int n;//生成元素的个数


	while(1)
	{
		printf("\n");
                printf("********************************************************************\n");
                printf("*                     1.......线性表初始化                         *\n");
                printf("*                                                                  *\n");
		printf("*                     2.......生成数据                             *\n");
		printf("*                                                                  *\n");
		printf("*                     3.......插入数据                             *\n");
		printf("*                                                                  *\n");
		printf("*                     4.......删除数据                             *\n");
		printf("*                                                                  *\n");
		printf("*                     5.......显示数据                             *\n");
		printf("*                                                                  *\n");
		printf("*                     6.......注销线性表                           *\n");
		printf("*                                                                  *\n");
		printf("*                     0.......退出程序                             *\n");
		printf("*                                                                  *\n");
		printf("********************************************************************\n");
		scanf("%d",&c);
        switch(c)
		{
        case 1:
            InitList(&L);
            printf("成功建立线性表!");
            break;
        case 2:
           {
            system("cls");
            printf("选择生成方式：1.....随机生成\t2.....文件读入\t3.....手动输入\n");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                printf("请输入生成元素的个数：\n");
                scanf("%d",&n);
                printf("请输入生成元素的最大值：\n");
                scanf("%d",&m);
                BuildList (&L,n,m);
                system("cls");
                break;
            case 2:
                break;
            case 3:
                printf("请选择输入个数：\n");
                scanf("%d",&n);
                printf("请输入元素：\n");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&e);
                    ListInsert(&L,i+1,e);
                }
                break ;
            default:
                break;
            }
           }
           break;
        case 3:

            printf("请输入要插入的位置：\n");
            scanf("%d",&k);
            printf("请输入要插入的元素：\n");
            scanf("%d",&e);
            ListInsert(&L,k,e);

            system("cls");
            break;
        case 4:
            printf("请输入要删除的位置：\n");
            scanf("%d",&k);
            i=ListDelete (&L,k);
            printf("成功将位于第%d位的元素‘%d’删除!\n",k,i);
            break;
        case 5:
            ShowList(&L);
            break;
        case 6:
            DestroyList(&L);
            printf("成功销毁线性表！\n");
            break;
        case 0:
            exit(0);
        default:
            continue;
		}

	}
	return 0;
}


*/


/*求集合的并集*/

void unionL(SqList *La,SqList Lb)
{
    int La_len;
    int Lb_len;
    int i;
    ElemType e;

    La_len=ListLength(*La);
    Lb_len=ListLength(Lb);

	for (i=1;i<=Lb_len;i++)
    {
    	GetElem(Lb,i,&e);

		if (!LocateElem(*La,e))
    /* 在La中没有找到与Lb相等的元素 */
    /*LocateElem返回非空 , !LocatElem即为空*/
    
        ListInsert(La,++La_len,e);/*在La尾部插入新元素*/
    }
}

int main()
{
    SqList L;
    ElemType e;
    Status i;
    int j,k;

    i=InitList(&L);

    printf("初始化 L 后：L.length=%d\n",L.length);

    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);

    printf("在 L 的表头依次插入 1～5 后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    i=ListEmpty(L);
    printf("L 是否空：i=%d(1:是 0:否)\n",i);


    i=ClearList(&L);
    printf("清空 L 后：L.length=%d\n",L.length);

    i=ListEmpty(L);
    printf("L 是否空：i=%d(1:是 0:否)\n",i);


    for(j=1;j<=10;j++)
        ListInsert(&L,j,j);

    printf("在 L 的表尾依次插入 1～10 后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在 L 的表头插入 0 后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("第 5 个元素的值为：%d\n",e);

    for(j=3;j<=4;j++)
    {
        k=LocateElem(L,j);
        if(k)
            printf("第%d 个元素的值为%d\n",k,j);
        else
            printf("没有值为%d 的元素\n",j);

    }

    k=ListLength(L); /* k 为表长 */
 
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L,j,&e);     /*删除第 j 个数据 */
        if(i==ERROR)
            printf("删除第%d 个数据失败\n",j);

        else
            printf("删除第%d 个的元素值为：%d\n",j,e);

    }

    printf("依次输出 L 的元素：");
    ListTraverse(L);

    j=5;
    ListDelete(&L,j,&e); /*  删除第 5 个数据 */
    printf("删除第%d 个的元素值为：%d\n",j,e);

    printf("依次输出 L 的元素：");
    ListTraverse(L);

    /*构造一个有 10 个数的 Lb*/
    
    SqList Lb;
    i=InitList(&Lb);

    for(j=6;j<=15;j++)
        i=ListInsert(&Lb,1,j);
        
    printf("依次输出 Lb 的元素：");    
    ListTraverse(Lb); 
    
    unionL(&L,Lb);

    printf("依次输出合并了 Lb 的 L 的元素：");
    ListTraverse(L);

    return 0;
}

