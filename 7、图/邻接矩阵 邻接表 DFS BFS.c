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

#define MAXSIZE 9 /*  �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9




typedef int Status;  /* Status �Ǻ���������,��ֵ�Ǻ������״̬���룬�� OK �� */
typedef int Boolean; /* Boolean �ǲ�������,��ֵ�� TRUE �� FALSE */

typedef char VertexType; /*  ��������Ӧ���û����� */
typedef int EdgeType; /*  ���ϵ�Ȩֵ����Ӧ���û����� */


/*  �ڽӾ���ṹ****************** */
typedef struct
{
    VertexType vexs[MAXVEX]; /*  ����� */
    EdgeType arc[MAXVEX][MAXVEX];/*  �ڽӾ��󣬿ɿ����߱� */
    int numVertexes, numEdges; /*  ͼ�е�ǰ�Ķ������ͱ��� */
}MGraph;

/*  �ڽӱ�ṹ****************** */
typedef struct EdgeNode /*  �߱��� */
{
    int adjvex;	/*  �ڽӵ���,�洢�ö����Ӧ���±� */
    int weight;	/*  ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
    struct EdgeNode *next; /*  ����,ָ����һ���ڽӵ� */
}EdgeNode;

typedef struct VertexNode /*  ������� */
{
    int in;	/*  ������� */
    char data; /*  ������,�洢������Ϣ */ EdgeNode *firstedge;/*  �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];


typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges; /*  ͼ�е�ǰ�������ͱ��� */
}graphAdjList,*GraphAdjList;






/*  �õ��Ķ��нṹ�뺯��********************************** */

/*  ѭ�����е�˳��洢�ṹ */
typedef struct
{
    int data[MAXSIZE];
    int front;	/*  ͷָ�� */
    int rear;	/*  βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}Queue;

/*  ��ʼ��һ���ն��� Q */
Status InitQueue(Queue *Q)
{
    Q->front=0;
    Q->rear=0;
    return	OK;
}


/*  ������ Q Ϊ�ն���,�򷵻� TRUE,���򷵻� FALSE */
Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear) /*  ���пյı�־ */
    return TRUE;

    else
    return FALSE;

}
/*  ������δ���������Ԫ�� e Ϊ Q �µĶ�βԪ�� */
Status EnQueue(Queue *Q,int e)
{
    if ((Q ->rear+1)%MAXSIZE == Q->front)  /*  ���������ж� */
        return ERROR;
    Q->data[Q->rear]=e;	/*  ��Ԫ�� e ��ֵ����β */
    Q->rear=(Q->rear+1)%MAXSIZE;/* rear ָ�������һλ�ã� */
/*  ���������ת������ͷ�� */
    return	OK;
}


/*  �����в��գ���ɾ�� Q �ж�ͷԪ�أ��� e ������ֵ */
Status DeQueue(Queue *Q,int *e)
{
    if (Q->front == Q->rear)	/*  ���пյ��ж� */
        return ERROR;
    *e=Q->data[Q->front];	/*  ����ͷԪ�ظ�ֵ�� e */
    Q->front=(Q->front+1)%MAXSIZE; /* front ָ�������һλ�ã� */
/*  ���������ת������ͷ�� */
    return	OK;
}
void CreateMGraph(MGraph *G)
{
    int i, j;
    printf("input numedges and numvertexes:\n")
    scanf("%d",&G->numEdges);
    scanf("%d",&G->numVertexes);

/*  ���붥����Ϣ����������� */
    for(i=0;i<G->numVertexes;i++)
    {
        scanf("%c",&G->vexs[i]);
    }
/* ����߱���Ϣ�������ڽӾ��� */
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
        {
            scanf("%d",G->arc[i][j])
        }



}


Boolean visited[MAXVEX]; /*  ���ʱ�־������ */

/*  �ڽӾ����������ȵݹ��㷨 */
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);/*  ��ӡ���㣬Ҳ������������ */

    for(j = 0; j < G.numVertexes; j++)
        if(G.arc[i][j] == 1 && !visited[j])//�бߣ���δ�����ʹ�
            DFS(G, j);/*  ��Ϊ���ʵ��ڽӶ���ݹ���� */
}


/*  �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G)
{
    int i;
    for(i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; /*  ��ʼ���ж���״̬����δ���ʹ�״̬ */
    for(i = 0; i < G.numVertexes; i++)
        if(!visited[i]) /*  ��δ���ʹ��Ķ������ DFS��������ͨͼ��ֻ��ִ��һ�� */
            DFS(G, i);
}
/*  �ڽӾ���Ĺ�ȱ����㷨 */
void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for(i = 0; i < G.numVertexes; i++)
    visited[i] = FALSE;
    InitQueue(&Q);	/*  ��ʼ��һ�����õĶ��� */
    for(i = 0; i < G.numVertexes; i++)	/*  ��ÿһ��������ѭ�� */
    {
        if (!visited[i])   /*  ����δ���ʹ��ʹ��� */
        {
            visited[i]=TRUE;	/*  ���õ�ǰ������ʹ� */
            printf("%c ", G.vexs[i]);/*  ��ӡ���㣬Ҳ������������ */
            EnQueue(&Q,i);	/*  ���˶�����β */
            while(!QueueEmpty(Q)) /*  ����ǰ���в�Ϊ�� */
            {
                DeQueue(&Q,&i);   /*  ����ͷԪ�س����У���ֵ�� i */
                for(j=0;j<G.numVertexes;j++)
                {
/*  �ж������������뵱ǰ������ڱ���δ���ʹ�	*/
                    if(G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j]=TRUE;	/*  ���ҵ��Ĵ˶�����Ϊ�ѷ���   */
                        printf("%c ", G.vexs[j]);   /*  ��ӡ���� */
                        EnQueue(&Q,j);	/*  ���ҵ��Ĵ˶��������	*/
                    }

                }
            }
        }
    }
}


/*  �ڽӱ��������ȵݹ��㷨 */
void DFS1(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ",GL->adjList[i].data);/*  ��ӡ����,Ҳ������������ */
    p = GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
        DFS(GL, p->adjvex);/*  ��Ϊ���ʵ��ڽӶ���ݹ���� */
        p = p->next;
    }
}
/*  �ڽӱ����ȱ������� */
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i = 0; i < GL->numVertexes; i++)
    visited[i] = FALSE; /*  ��ʼ���ж���״̬����δ���ʹ�״̬ */
    for(i = 0; i < GL->numVertexes; i++)
    if(!visited[i]) /*  ��δ���ʹ��Ķ������ DFS,������ͨͼ,ֻ��ִ��һ�� */
        DFS(GL, i);
}

/*  �ڽӱ�Ĺ�ȱ����㷨 */
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for(i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);
    for(i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i]=TRUE;
            printf("%c ",GL->adjList[i].data);/*  ��ӡ����,Ҳ������������ */ EnQueue(&Q,i);
            while(!QueueEmpty(Q))

            {
                DeQueue(&Q,&i);
                p = GL->adjList[i].firstedge;	/*  �ҵ���ǰ����ı߱�����ͷָ�� */
                while(p)
                {
                    if(!visited[p->adjvex])	/*  ���˶���δ������ */
                    {
                        visited[p->adjvex]=TRUE;
                        printf("%c ",GL->adjList[p->adjvex].data);
                        EnQueue(&Q,p->adjvex);	/*  ���˶�������� */
                    }
                p = p->next;	/*  ָ��ָ����һ���ڽӵ� */
                }
            }
        }
    }
}









