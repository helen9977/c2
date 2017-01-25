#include"main.c"

int main()
{
    SqStack S;
    int n,m;
    int e;

    InitStack(&S);

    printf("请输入一个十位数：\n");
    scanf("%d",&n);

    printf("请输入要转化的进制\n");
    scanf("%d",&m);

    while(n)
    {
        Push(&S, n % m);
        n=n/m;
    }

    while(!StackEmpty(S))
    {
        Pop(&S,&e);
        printf("(%d)",e);
    }
    return 0;
 }
