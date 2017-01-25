#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define     OK            1
#define     ERROR         0
#define     OVERFLOW     -1

#define     Status       int

//���������ڵ����Ͷ���
typedef  struct  HTNodew
{
    unsigned  int weight;//Ȩ��
    unsigned  int parent,lchild,rchild;//���ڵ㣬���ӣ��Һ���(�޷������ͣ�
}HTNode,*HuffmanTree;

typedef char **  HuffmanCode;

HuffmanTree HT;

//ѡȡ��С�Ķ�������
Status Select(int n,int *s1,int *s2,int *foot);

//�����������
Status  HuffmanCoding(HuffmanCode *HC, int  n,unsigned int *w)
{
    /*
    **w���n���ַ���Ȩֵ��������0���������������HT���������n���ַ��Ĺ���������HC
    */
    if(n<=0)
        return ERROR;
    int m=2*n-1;           //m���ܹ���Ҫ�Ľڵ����

    HT = (HuffmanTree)malloc(sizeof(HTNode)*(m+1));      //0�ŵ�Ԫ��ʹ�ã��±��1��ʼ��m����
    int  i=1;
    HuffmanTree p;
    for(p = HT,p++;i<=n;i++,p++,w++)//���θ��ڵ㸳ֵ����������p++����Ϊ�±��1��ʼ��
    {
        (*p).weight = *w;//��ʼ���ڵ㣬���ӽڵ���Һ��ӽڵ��Ϊ0
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).lchild = 0;
    }

    for(;i<= m;i++,p++)              //�������n-1���ڵ㸳ֵ
    {
        (*p).weight = 0;//��ʼ���ڵ㣬���ӽڵ���Һ��ӽڵ��Ϊ0
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).lchild = 0;
    }
    //����һ��m���ȵ������¼�ڵ��Ƿ񱻷��ʹ�
    int *foot=(int *)malloc(sizeof(int)*(m+1));//���±�Ҳ�Ǵ�1��ʼ��Ϊ�˺���������ö�Ӧ��
    int *s=foot;
    s++;
    int k;
    for( k=1;k<=m;k++)
    {
        *(s++)=0;//��ʼ��Ϊ0 �����з��ʹ�����ֵ1����ʾ�Ѿ����ʹ���
    }
    /*
    **������������
    */
    for(i = n+1;i<=m;i++)   //���θ������n-1���ڵ㸳ֵ����n+1��m��
    {
        /*
        **��HT[1...i-1]ѡ��parentΪ0 ��weight��С�Ķ����ڵ㣬�����Ϊs1��s2
        */
        int *s1 = (int *)malloc(sizeof(int ));
        int *s2 = (int *)malloc(sizeof(int));
        if(!s1||!s2)
        {
            printf("�����ڴ�ռ����.\n");
            return ERROR;
        }

        Select(i-1,s1,s2,foot);
        HT[*s1].parent = i;
        HT[*s2].parent = i;
        HT[i].lchild = *s1;
        HT[i].rchild = *s2;
        HT[i].weight = HT[*s1].weight + HT[*s2].weight;

    }



    //-----��Ҷ�ӵ����ڵ�������ÿ���ַ��Ĺ���������---------//

    *HC=(HuffmanCode)malloc(sizeof(char *)*(n+1));//��1��ʼ�������±�1

    char *cd = (char *)malloc(sizeof(char)*n);   //���������Ĺ������䣨n���ַ���ı�����Ҫn-1���ռ䣬���Ͻ������ţ�
    cd[n-1]='\0';//���������

    int  start;//��������λ��
    for(i = 1;i<=n;i++)//����ַ������������
    {
        start = n-1;//���������λ��
        int c,f;
        start--;
        for(c = i,f = HT[i].parent;f != 0;c = f,f = HT[f].parent)
        {
            if(HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            start-=1;
        }
        start+=1;//����һ��Ҫ��1  �����������ڴ�ռ�
        (*HC)[i]=(char *)malloc((n-start)*sizeof(char));//����n-start��char�ռ伴��
        strcpy((*HC)[i],&cd[start]);
        char *p=(*HC)[i];
        printf("HuffManNode of %d is(from root to child) ��\n",HT[i].weight);
        printf("%d:------>%s ",HT[i].weight,p);

        printf("\n");

    }
    free(cd);
    return OK;
}


Status Select(int n,int *s1,int *s2,int *foot)
{
    int i,j;
    int min=65536;
    int temp;

    for(i=1;i<=n;i++)//�ҵ���һ����С��ֵ���±�
    {
        if(HT[i].weight<min&&foot[i]==0)
        {
            min=HT[i].weight;
            temp=i;//��¼���յ���Сֵ���±�
        }
    }
    foot[temp]=1;
    *s1=temp;


    min=65536;
    for(j=1;j<=n;j++)//Ѱ����С�ڵ��±�
    {
        if(HT[j].weight<min&&j!=(*s1)&&foot[j]==0)
        {
            min=HT[j].weight;
            temp=j;
        }
    }
    foot[temp]=1;
    *s2=temp;
    //����*s1��*s2����*s1ָ��С������  *s2ָ��������
    temp=*s1;
    *s1=*s2;
    *s2=temp;
    return OK;

}

int main()
{

    int n;
    printf("Input the number of weight:\n");
    scanf("%d",&n);
    unsigned int *w=(unsigned int *)malloc(sizeof(unsigned int)*n);
    printf("Input The weight!\n");

    unsigned s;
    unsigned *p=w;
    int i = 1;
    // unsigned int p[8]={5,29,7,8,14,23,3,11};
    while(i<=n)
    {
        scanf("%ud",&s);
        *p=s;
        i++;
        p++;
    }
    p=w;
    HuffmanCode *HC=(HuffmanCode *)malloc(sizeof(HuffmanCode));
    if(!HC)
    {
        printf("�����ʼ�ڴ�ռ����.\n");
        return 0;
    }
    HuffmanCoding(HC,n,p);
    return 0;
}
