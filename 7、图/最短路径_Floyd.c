/* Floyd 算法，求网图 G 中各顶点 v 到其余顶点 w 的最短路径 P[v][w]及带权长度 D[v][w]。*/
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{
    int v,w,k;
    for(v=0; v<G.numVertexes; ++v) /*  初始化 D 与 P */
    {
        for(w=0; w<G.numVertexes; ++w)
        {
            (*D)[v][w]=G.arc[v][w];  /* D[v][w]值即为对应点间的权值 */ (*P)[v][w]=w;	/*  初始化 P */
        }
    }
    for(k=0; k<G.numVertexes; ++k)
    {
        for(v=0; v<G.numVertexes; ++v)
        {
            for(w=0; w<G.numVertexes; ++w)
            {
                if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
                {/*  如果经过下标为 k 顶点路径比原两点间路径更短 */
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    /*  将当前两点间权值设为更小的一个*/
                    (*P)[v][w]=(*P)[v][k];
                    /*  路径设置为经过下标为 k 的顶点 */
                }
            }
        }
    }
}
