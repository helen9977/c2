#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*  存储空间初始分配量 */



void GetNext(char *t,int *next)
{
    int j=0;
    int k=-1;
    next[0]=-1;
    while(j<strlen(t)-1)
    {
        if(k==-1||t[j]==t[k])
        {
            j++;
            k++;
            next[j]=k;
        }
    else
        k=next[k];
    }

}

int KMP(char *s, char *t)
{
    int i;
    int j = 0;
    int *next = (int*)calloc(strlen(t),sizeof(int));//n设置为数组的容量.void *calloc(int n,int size);

    GetNext(t,next);

    printf("next[] = ");
    for(i=0;i<strlen(t);i++)
        printf("%d ",next[i]);

    i=0;
    while(i<strlen(s))
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        j = next[j];

        if(j==strlen(t))
            return (i-strlen(t));
    }

    free(next);

    return -1;
}

