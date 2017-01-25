#include"main2.c"
int main()
{
    LinkStack S;
    InitStack(&S);
    char e;
    SElemType num;
    
    scanf("%c",&e);
    while(e != '#')
    {
    	if(e >= '0' && e <= '9' )
    	
    	{
    		num=e-'0';
       		Push(&S,num);
       	} 
        
        else 
    	{
        	int a,b;
        	Pop(&S,&a);
        	Pop(&S,&b);
        	switch(e)
        	
       			{
        			case '+':
            			Push(&S,b+a);
            			break;
      				case '-':
            			Push(&S,b-a);
            			break;
        			case '*':
            			Push(&S,b*a);
            			break;
        			case '/':
            			Push(&S,b/a);
            			break;
        		}
        }
        
        scanf("%c",&e);
    }
    GetTop(S,&num);
    printf("%d",num);
    return 0;
}
