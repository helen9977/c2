#include"next.c"
int main()
{
    char *S;
    char *T;
    int A;
    FILE *fp1,*fp2;
    if((fp1=fopen("html.txt","r"))==NULL)
    {
        printf("can not open the file");
        exit(0);
    }
   /* if((fp2=fopen("kmp.txt","w"))==NULL)
    {
        printf("can not open the file");
        exit(0);
    }*/
    while(!feof(fp1))
    {
        S=fgetc(fp1);

    }
    printf("\n");
    gets(T);
    A=KMP(S,T);
    printf("%d",A);

    fclose(fp1);
    //fclose(fp2);

    return 0;
}

