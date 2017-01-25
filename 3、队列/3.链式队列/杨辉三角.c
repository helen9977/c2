#include"main3.c"
int main()
{
    LinkQueue Q;
    InitQueue (&Q);
    int i,j,n,s1,s2;
    printf("请输入杨辉三角的行数：\n");
    scanf("%d",&n);
    printf("\n");
    EnQueue(&Q,1);
    //GetHead(Q,&s1);
    //printf("%d\n",s1);
    
    for(i=1;i<=n;i++)
    {
        s1=0;
        for(j=1;j<=i;j++)
        {
            //GetHead(Q,&s2);
            DeQueue(&Q,&s2);
            printf("%d ",s1+s2);
            EnQueue(&Q,s1+s2);
            s1=s2;

        }
        printf("1\n");
        EnQueue(&Q,1);
    }
    return 0;
}
