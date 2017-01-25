#include <stdio.h>

#define MAXSIZE 12500
#define MAXRC 200

typedef int ElemType;

typedef struct{
	int i;
	int j;
	ElemType e;
}Triple;

typedef struct{
	Triple data[MAXSIZE + 1];
	int rpos[MAXRC + 1];
	int mu, nu, tu; //矩阵的行数，列数和非零元个数
}RLSMatrix;

int CreateSMatrix(RLSMatrix *M){
    int i, j, m ,n, k = 1, row, num[MAXRC + 1], t;
    ElemType e;
    scanf ("%d%d", &(*M).mu, &(*M).nu);
    (*M).data[0].i = 0;
    (*M).tu = 0;

    for (i = 1; i <= (*M).mu; i ++)
        for (j = 1; j <= (*M).nu; j ++){
        	scanf ("%d", &e);
        	if (e != 0){
        		(*M).tu ++;
        		(*M).data[k].i = i;
        		(*M).data[k].j = j;
        		(*M).data[k].e = e;
				k ++;
			}
		}
    for (row = 1; row <= (*M).tu; row ++)
        num[row] = 0;
    for (t = 1; t <= (*M).tu; t ++)
        num[(*M).data[t].i] ++;
    (*M).rpos[1] = 1;
    for (row = 2; row <= (*M).mu; row ++)
        (*M).rpos[row] = (*M).rpos[row - 1] + num[row - 1];

	return 1;
}

int MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q){
    int arow, tp, p, q, t, ccol, brow;
    if (M.nu != N.mu)
        return 0;
    (*Q).mu = M.mu;
    (*Q).nu = N.nu;
    (*Q).tu = 0;
    if (M.tu * N.tu != 0){
        for (arow = 1; arow <= M.mu; arow ++){ //处理每一行
            int ctemp[MAXRC + 1] = {0}; //当前行各元素累加器清零
            (*Q).rpos[arow] = (*Q).tu + 1;
            if (arow < M.mu)
                tp = M.rpos[arow + 1];
            else
                tp = M.tu + 1;
            for (p = M.rpos[arow]; p < tp; p ++){//对当前行的每一个元素
                brow = M.data[p].j;//到对应元在N中的列号
                if (brow < N.mu)
                    t = N.rpos[brow + 1];
                else
                    t = N.tu + 1;
                for (q = N.rpos[brow]; q < t; q ++){
                    ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                }
            }
            for (ccol = 1; ccol <= (*Q).nu; ccol ++)
                if (ctemp[ccol]){
                    if (++ (*Q).tu > MAXSIZE)//这里Q.tu已经加一
                        return 0;
                    (*Q).data[(*Q).tu].e = ctemp[ccol];
                    (*Q).data[(*Q).tu].i = arow;
                    (*Q).data[(*Q).tu].j = ccol;
                }
        }
    }
    return 1;
}

int PrintSMatrix(RLSMatrix M){
	int i, j, k = 1;
	for (i = 1; i <= M.mu; i ++){
		for(j = 1; j <= M.nu; j ++){
			if ((M.data[k].i == i) && (M.data[k].j == j)){
			    printf ("%d ", M.data[k].e);
			    k ++;
		    }
		    else
		        printf ("0 ");
	    }
	    printf ("\n");
	}
}

int main (){
    RLSMatrix M, N, Q;
    CreateSMatrix(&M);
    CreateSMatrix(&N);
    MultSMatrix(M, N, &Q);
    PrintSMatrix(Q);
    return 0;
}
