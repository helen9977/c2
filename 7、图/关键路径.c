#include"tuopupaixu.c"
/*  ��ؼ�·��,GL Ϊ����������� G �ĸ���ؼ�� */
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i,gettop,k,j;
    int ete,lte;	/*  ��������緢��ʱ�����ٷ���ʱ����� */

    TopologicalSort(GL);	/*  ���������У��������� etv �� stack2 ��ֵ */
    ltv=(int *)malloc(GL->numVertexes*sizeof(int));/*  �¼����緢��ʱ������ */
    for(i=0; i<GL->numVertexes; i++)
        ltv[i]=etv[GL->numVertexes-1];	/*  ��ʼ�� */

    printf("etv:\t");
    for(i=0; i<GL->numVertexes; i++)
        printf("%d -> ",etv[i]);
    printf("\n");

    while(top2!=0)	/*  ��ջ���� ltv */
    {
        gettop=stack2[top2--];
        for(e = GL->adjList[gettop].firstedge; e; e = e->next)	/*  ��������¼������ ����ʱ�� ltv ֵ */
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

    for(j=0; j<GL->numVertexes; j++)	/*  �� ete,lte �͹ؼ�� */
    {
        for(e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k=e->adjvex;
            ete = etv[j];		/*  ����緢��ʱ�� */
            lte = ltv[k] - e->weight; /*  ���ٷ���ʱ�� */
            if(ete == lte)	/*  ������ȼ��ڹؼ�·���� */
        printf("<v%d-v%d>length:%d\n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
        }
    }
}
