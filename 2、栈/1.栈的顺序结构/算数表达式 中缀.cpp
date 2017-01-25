#include"main.c"
int main()
{
	SqStack NUM,OPE;//建立一个运算数栈，一个运算符栈。 
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
	//YC宝宝棒棒哒~  
	//YC宝宝棒棒哒~
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
					printf("\n\a奕超是大笨蛋\n\n");
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
		if(c=='\n')//以\n结尾 
			break;
	}
	//if(StackEmpty(OPE))
		printf("你是%lf",GetTop(NUM)); 
	return 0;
}

//many thanks for you ~

