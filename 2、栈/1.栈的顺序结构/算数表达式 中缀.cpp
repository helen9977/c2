#include"main.c"
int main()
{
	SqStack NUM,OPE;//����һ��������ջ��һ�������ջ�� 
	InitStack(&NUM); 
	InitStack(&OPE);
	char c;
	double num=0, a, b;
	int M;
	int e[128]; 
	int y[7][7]={{1,1,-1,-1,-1,1,1},\
				{1,1,-1,-1,-1,1,1},\
				{1,1,1,1,-1,1,1},\
				{1,1,1,1,-1,1,1},\
				{-1,-1,-1,-1,-1,0,3},\
				{1,1,1,1,3,1,1},\
				{-1,-1,-1,-1,-1,3,0}};
	e['+']=0;
	e['-']=1;
	e['*']=2;
	e['/']=3;
	e['(']=4;
	e[')']=5;
	e['\n']=6;
	//YC����������~  
	//YC����������~
	Push(&OPE,'\n'); 
	while(scanf("%c",&c))
	{
		if(c>='0'&&c<='9')
		{
			num*=10;
			num+=c-'0';
			M=1; 
			continue;
		}
		else if(M)
		{
			M=0;
			Push(&NUM,(double)num);
			num=0;
		}
		//input numbers
		
		while(y[e[(int)GetTop(OPE)]][e[c]]==1)
		{
			switch((int)GetTop(OPE))
			{
				case '+':
				{
					Pop(&NUM,&b);
					Pop(&NUM,&a);
					Push(&NUM,a+b); 
					Pop(&OPE,&a); 
					break;
				}
				case '-':
				{
					Pop(&NUM,&b);
					Pop(&NUM,&a);
					Push(&NUM,a-b); 
					Pop(&OPE,&a); 
					break;
				}
				case '*':
				{
					Pop(&NUM,&b);
					Pop(&NUM,&a);
					Push(&NUM,a*b); 
					Pop(&OPE,&a); 
					break;
				}
				case '/':
				{
					Pop(&NUM,&b);
					Pop(&NUM,&a);
					Push(&NUM,a/b); 
					Pop(&OPE,&a); 
					break;
				}
				default:
					printf("\n\a�ȳ��Ǵ󱿵�\n\n");
					break;
			}
		}
		if(y[e[(int)GetTop(OPE)]][e[c]]==-1)
		{
			Push(&OPE,(double)c);
		}
		else
		{
			Pop(&OPE,&a);
		}
		if(c=='\n')//��\n��β 
			break;
	}
	//if(StackEmpty(OPE))
		printf("����%lf",GetTop(NUM)); 
	return 0;
}

//many thanks for you ~

