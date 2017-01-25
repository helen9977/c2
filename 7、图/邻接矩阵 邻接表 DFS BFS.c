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

#define MAXSIZE 9 /*  存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9




typedef int Status;  /* Status 是函数的类型,其值是函数结果状态代码，如 OK 等 */
typedef int Boolean; /* Boolean 是布尔类型,其值是 TRUE 或 FALSE */

typedef char VertexType; /*  顶点类型应由用户定义 */
typedef int EdgeType; /*  边上的权值类型应由用户定义 */


/*  邻接矩阵结构****************** */
typedef struct
{
    VertexType vexs[MAXVEX]; /*  顶点表 */
    EdgeType arc[MAXVEX][MAXVEX];/*  邻接矩阵，可看作边表 */
    int numVertexes, numEdges; /*  图中当前的顶点数和边数 */
}MGraph;

/*  邻接表结构****************** */
typedef struct EdgeNode /*  边表结点 */
{
    int adjvex;	/*  邻接点域,存储该顶点对应的下标 */
    int weight;	/*  用于存储权值,对于非网图可以不需要 */
    struct EdgeNode *next; /*  链域,指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /*  顶点表结点 */
{
    int in;	/*  顶点入度 */
    char data; /*  顶点域,存储顶点信息 */ EdgeNode *firstedge;/*  边表头指针 */
}VertexNode, AdjList[MAXVEX];


typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges; /*  图中当前顶点数和边数 */
}graphAdjList,*GraphAdjList;






/*  用到的队列结构与函数********************************** */

/*  循环队列的顺序存储结构 */
typedef struct
{
    int data[MAXSIZE];
    int front;	/*  头指针 */
    int rear;	/*  尾指针，若队列不空，指向队列尾元素的下一个位置 */
}Queue;

/*  初始化一个空队列 Q */
Status InitQueue(Queue *Q)
{
    Q->front=0;
    Q->rear=0;
    return	OK;
}


/*  若队列 Q 为空队列,则返回 TRUE,否则返回 FALSE */
Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear) /*  队列空的标志 */
    return TRUE;

    else
    return FALSE;

}
/*  若队列未满，则插入元素 e 为 Q 新的队尾元素 */
Status EnQueue(Queue *Q,int e)
{
    if ((Q ->rear+1)%MAXSIZE == Q->front)  /*  队列满的判断 */
        return ERROR;
    Q->data[Q->rear]=e;	/*  将元素 e 赋值给队尾 */
    Q->rear=(Q->rear+1)%MAXSIZE;/* rear 指针向后移一位置， */
/*  若到最后则转到数组头部 */
    return	OK;
}


/*  若队列不空，则删除 Q 中队头元素，用 e 返回其值 */
Status DeQueue(Queue *Q,int *e)
{
    if (Q->front == Q->rear)	/*  队列空的判断 */
        return ERROR;
    *e=Q->data[Q->front];	/*  将队头元素赋值给 e */
    Q->front=(Q->front+1)%MAXSIZE; /* front 指针向后移一位置， */
/*  若到最后则转到数组头部 */
    return	OK;
}
void CreateMGraph(MGraph *G)
{
    int i, j;
    printf("input numedges and numvertexes:\n")
    scanf("%d",&G->numEdges);
    scanf("%d",&G->numVertexes);

/*  读入顶点信息，建立顶点表 */
    for(i=0;i<G->numVertexes;i++)
    {
        scanf("%c",&G->vexs[i]);
    }
/* 读入边表信息，建立邻接矩阵 */
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
        {
            scanf("%d",G->arc[i][j])
        }



}


Boolean visited[MAXVEX]; /*  访问标志的数组 */

/*  邻接矩阵的深度优先递归算法 */
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);/*  打印顶点，也可以其它操作 */

    for(j = 0; j < G.numVertexes; j++)
        if(G.arc[i][j] == 1 && !visited[j])//有边，且未被访问过
            DFS(G, j);/*  对为访问的邻接顶点递归调用 */
}


/*  邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G)
{
    int i;
    for(i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; /*  初始所有顶点状态都是未访问过状态 */
    for(i = 0; i < G.numVertexes; i++)
        if(!visited[i]) /*  对未访问过的顶点调用 DFS，若是连通图，只会执行一次 */
            DFS(G, i);
}
/*  邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for(i = 0; i < G.numVertexes; i++)
    visited[i] = FALSE;
    InitQueue(&Q);	/*  初始化一辅助用的队列 */
    for(i = 0; i < G.numVertexes; i++)	/*  对每一个顶点做循环 */
    {
        if (!visited[i])   /*  若是未访问过就处理 */
        {
            visited[i]=TRUE;	/*  设置当前顶点访问过 */
            printf("%c ", G.vexs[i]);/*  打印顶点，也可以其它操作 */
            EnQueue(&Q,i);	/*  将此顶点入尾 */
            while(!QueueEmpty(Q)) /*  若当前队列不为空 */
            {
                DeQueue(&Q,&i);   /*  将队头元素出队列，赋值给 i */
                for(j=0;j<G.numVertexes;j++)
                {
/*  判断其它顶点若与当前顶点存在边且未访问过	*/
                    if(G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j]=TRUE;	/*  将找到的此顶点标记为已访问   */
                        printf("%c ", G.vexs[j]);   /*  打印顶点 */
                        EnQueue(&Q,j);	/*  将找到的此顶点入队列	*/
                    }

                }
            }
        }
    }
}


/*  邻接表的深度优先递归算法 */
void DFS1(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ",GL->adjList[i].data);/*  打印顶点,也可以其它操作 */
    p = GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
        DFS(GL, p->adjvex);/*  对为访问的邻接顶点递归调用 */
        p = p->next;
    }
}
/*  邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i = 0; i < GL->numVertexes; i++)
    visited[i] = FALSE; /*  初始所有顶点状态都是未访问过状态 */
    for(i = 0; i < GL->numVertexes; i++)
    if(!visited[i]) /*  对未访问过的顶点调用 DFS,若是连通图,只会执行一次 */
        DFS(GL, i);
}

/*  邻接表的广度遍历算法 */
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
            printf("%c ",GL->adjList[i].data);/*  打印顶点,也可以其它操作 */ EnQueue(&Q,i);
            while(!QueueEmpty(Q))

            {
                DeQueue(&Q,&i);
                p = GL->adjList[i].firstedge;	/*  找到当前顶点的边表链表头指针 */
                while(p)
                {
                    if(!visited[p->adjvex])	/*  若此顶点未被访问 */
                    {
                        visited[p->adjvex]=TRUE;
                        printf("%c ",GL->adjList[p->adjvex].data);
                        EnQueue(&Q,p->adjvex);	/*  将此顶点入队列 */
                    }
                p = p->next;	/*  指针指向下一个邻接点 */
                }
            }
        }
    }
}









