#include"main.c"

int main()
{
    SqStack S;
    int n,m;
    int e;

    InitStack(&S);

    printf("������һ��ʮλ����\n");
    scanf("%d",&n);

    printf("������Ҫת���Ľ���\n");
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
