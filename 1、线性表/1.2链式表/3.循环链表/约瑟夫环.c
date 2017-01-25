#include "main3.c"
int main()
{
    LinkList head;
    int n,m,k;
    printf("请输入人数N:\n");
    scanf("%d",&n);
    printf("请输入数字m:\n");
    scanf("%d",&m);
    printf("请输入起始位置：\n");
    scanf("%d",&k);
    CreateLinklist(&head,n);
    printf("玩家信息：\n");
    PrintLinklist(&head,n);
    printf("依次被选出的是:\n");
    joseph(head,n,k,m);
    return 0;
}
