#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
float s[25];
int top=-1;
float operation(char op,float op1,float op2)
{
	switch(op)
	{
	    case '+':return(op1+op2);
	    case '-':return(op1-op2);
	    case '*':return(op1*op2);
	    case '/':return(op1/op2);
	    case '%':return((int)op1%(int)op2);
	    case '^':return(pow(op1,op2));
	}
	return (0);
}
void push(float symbol)
{
    s[++top]=symbol;
}
float pop()
{
    return(s[top--]);
}
bool isdigit(char symbol){
	bool flag=false;
	for(int i=0; i<=9; i++){
		if(symbol-'0'==i){
			flag=true;
		}
	}
	return flag;
}
int main()
{
    char postfix[25],symbol;
    float op1,op2,res;int i;
    printf("enter the postfix expressin\n");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
      if(isdigit(symbol))  
        push(symbol-'0');
       else
        {
            op2=pop();
            op1=pop();
            res=operation(symbol,op1,op2);
            push(res);
        }
    }
    res=pop();
    printf("Result=%.2f",res);
}