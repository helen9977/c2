#include"tuopupaixu.c"
/*  求关键路径,GL 为有向网，输出 G 的各项关键活动 */
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i,gettop,k,j;
    int ete,lte;	/*  声明活动最早发生时间和最迟发生时间变量 */

    TopologicalSort(GL);	/*  求拓扑序列，计算数组 etv 和 stack2 的值 */
    ltv=(int *)malloc(GL->numVertexes*sizeof(int));/*  事件最早发生时间数组 */
    for(i=0; i<GL->numVertexes; i++)
        ltv[i]=etv[GL->numVertexes-1];	/*  初始化 */

    printf("etv:\t");
    for(i=0; i<GL->numVertexes; i++)
        printf("%d -> ",etv[i]);
    printf("\n");

    while(top2!=0)	/*  出栈是求 ltv */
    {
        gettop=stack2[top2--];
        for(e = GL->adjList[gettop].firstedge; e; e = e->next)	/*  求各顶点事件的最迟 发生时间 ltv 值 */
        {
            k=e->adjvex;
            if(ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }

    printf("ltv:\t");
    for(i=0; i<GL->numVertexes; i++)
        printf("%d -> ",ltv[i]);
    printf("\n");

    for(j=0; j<GL->numVertexes; j++)	/*  求 ete,lte 和关键活动 */
    {
        for(e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k=e->adjvex;
            ete = etv[j];		/*  活动最早发生时间 */
            lte = ltv[k] - e->weight; /*  活动最迟发生时间 */
            if(ete == lte)	/*  两者相等即在关键路径上 */
        printf("<v%d-v%d>length:%d\n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
        }
    }
}
