/*int main()
{

     SqList L;//����һ�����Ա�
     ElemType e,m;//����Ԫ�أ�����Ԫ�ص����ֵ
     int k;//�����ɾ����λ��
     int c;//���ڶ���ѡ�
     Status i;//���շ���ֵ
     int n;//����Ԫ�صĸ���


	while(1)
	{
		printf("\n");
                printf("********************************************************************\n");
                printf("*                     1.......���Ա��ʼ��                         *\n");
                printf("*                                                                  *\n");
		printf("*                     2.......��������                             *\n");
		printf("*                                                                  *\n");
		printf("*                     3.......��������                             *\n");
		printf("*                                                                  *\n");
		printf("*                     4.......ɾ������                             *\n");
		printf("*                                                                  *\n");
		printf("*                     5.......��ʾ����                             *\n");
		printf("*                                                                  *\n");
		printf("*                     6.......ע�����Ա�                           *\n");
		printf("*                                                                  *\n");
		printf("*                     0.......�˳�����                             *\n");
		printf("*                                                                  *\n");
		printf("********************************************************************\n");
		scanf("%d",&c);
        switch(c)
		{
        case 1:
            InitList(&L);
            printf("�ɹ��������Ա�!");
            break;
        case 2:
           {
            system("cls");
            printf("ѡ�����ɷ�ʽ��1.....�������\t2.....�ļ�����\t3.....�ֶ�����\n");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                printf("����������Ԫ�صĸ�����\n");
                scanf("%d",&n);
                printf("����������Ԫ�ص����ֵ��\n");
                scanf("%d",&m);
                BuildList (&L,n,m);
                system("cls");
                break;
            case 2:
                break;
            case 3:
                printf("��ѡ�����������\n");
                scanf("%d",&n);
                printf("������Ԫ�أ�\n");
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

            printf("������Ҫ�����λ�ã�\n");
            scanf("%d",&k);
            printf("������Ҫ�����Ԫ�أ�\n");
            scanf("%d",&e);
            ListInsert(&L,k,e);

            system("cls");
            break;
        case 4:
            printf("������Ҫɾ����λ�ã�\n");
            scanf("%d",&k);
            i=ListDelete (&L,k);
            printf("�ɹ���λ�ڵ�%dλ��Ԫ�ء�%d��ɾ��!\n",k,i);
            break;
        case 5:
            ShowList(&L);
            break;
        case 6:
            DestroyList(&L);
            printf("�ɹ��������Ա�\n");
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


/*�󼯺ϵĲ���*/

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
    /* ��La��û���ҵ���Lb��ȵ�Ԫ�� */
    /*LocateElem���طǿ� , !LocatElem��Ϊ��*/
    
        ListInsert(La,++La_len,e);/*��Laβ��������Ԫ��*/
    }
}

int main()
{
    SqList L;
    ElemType e;
    Status i;
    int j,k;

    i=InitList(&L);

    printf("��ʼ�� L ��L.length=%d\n",L.length);

    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);

    printf("�� L �ı�ͷ���β��� 1��5 ��L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    i=ListEmpty(L);
    printf("L �Ƿ�գ�i=%d(1:�� 0:��)\n",i);


    i=ClearList(&L);
    printf("��� L ��L.length=%d\n",L.length);

    i=ListEmpty(L);
    printf("L �Ƿ�գ�i=%d(1:�� 0:��)\n",i);


    for(j=1;j<=10;j++)
        ListInsert(&L,j,j);

    printf("�� L �ı�β���β��� 1��10 ��L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("�� L �ı�ͷ���� 0 ��L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("�� 5 ��Ԫ�ص�ֵΪ��%d\n",e);

    for(j=3;j<=4;j++)
    {
        k=LocateElem(L,j);
        if(k)
            printf("��%d ��Ԫ�ص�ֵΪ%d\n",k,j);
        else
            printf("û��ֵΪ%d ��Ԫ��\n",j);

    }

    k=ListLength(L); /* k Ϊ�� */
 
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L,j,&e);     /*ɾ���� j ������ */
        if(i==ERROR)
            printf("ɾ����%d ������ʧ��\n",j);

        else
            printf("ɾ����%d ����Ԫ��ֵΪ��%d\n",j,e);

    }

    printf("������� L ��Ԫ�أ�");
    ListTraverse(L);

    j=5;
    ListDelete(&L,j,&e); /*  ɾ���� 5 ������ */
    printf("ɾ����%d ����Ԫ��ֵΪ��%d\n",j,e);

    printf("������� L ��Ԫ�أ�");
    ListTraverse(L);

    /*����һ���� 10 ������ Lb*/
    
    SqList Lb;
    i=InitList(&Lb);

    for(j=6;j<=15;j++)
        i=ListInsert(&Lb,1,j);
        
    printf("������� Lb ��Ԫ�أ�");    
    ListTraverse(Lb); 
    
    unionL(&L,Lb);

    printf("��������ϲ��� Lb �� L ��Ԫ�أ�");
    ListTraverse(L);

    return 0;
}

