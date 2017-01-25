/* Floyd �㷨������ͼ G �и����� v �����ඥ�� w �����·�� P[v][w]����Ȩ���� D[v][w]��*/
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{
    int v,w,k;
    for(v=0; v<G.numVertexes; ++v) /*  ��ʼ�� D �� P */
    {
        for(w=0; w<G.numVertexes; ++w)
        {
            (*D)[v][w]=G.arc[v][w];  /* D[v][w]ֵ��Ϊ��Ӧ����Ȩֵ */ (*P)[v][w]=w;	/*  ��ʼ�� P */
        }
    }
    for(k=0; k<G.numVertexes; ++k)
    {
        for(v=0; v<G.numVertexes; ++v)
        {
            for(w=0; w<G.numVertexes; ++w)
            {
                if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
                {/*  ��������±�Ϊ k ����·����ԭ�����·������ */
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    /*  ����ǰ�����Ȩֵ��Ϊ��С��һ��*/
                    (*P)[v][w]=(*P)[v][k];
                    /*  ·������Ϊ�����±�Ϊ k �Ķ��� */
                }
            }
        }
    }
}
