#include "main3.c"
int main()
{
    LinkList head;
    int n,m,k;
    printf("����������N:\n");
    scanf("%d",&n);
    printf("����������m:\n");
    scanf("%d",&m);
    printf("��������ʼλ�ã�\n");
    scanf("%d",&k);
    CreateLinklist(&head,n);
    printf("�����Ϣ��\n");
    PrintLinklist(&head,n);
    printf("���α�ѡ������:\n");
    joseph(head,n,k,m);
    return 0;
}
