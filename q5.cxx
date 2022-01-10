#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100
char stack[MAX];
char infix[MAX], postfix[MAX];
int top=-1;

int precedence(char symbol){
	switch(symbol){
		case '^':
			return 3;
		case '/':
		case '*':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

void print(){
	int i=0;
	printf("The equivalent postfix expression is:");
	while(postfix[i]){
		printf("%c",postfix[i++]);
	}
	printf("\n");
}

void push(char c){
	if(top==MAX-1){
		printf("stack overflow\n");
		return;
	}
	top++;
	stack[top]=c;
}

char pop(){
	char c;
	if(top==-1){
		printf("stack underflow\n");
		exit(1);
	}
	c=stack[top];
	top=top-1;
	return c;
}

int isEmpty(){
	if(top==-1)
		return 1;
		
	else
		return 0;
}		

void infixToPostfix(){
	char next;
	char symbol;
	int j=0;
	for(int i=0; i<strlen(infix); i++){
		symbol=infix[i];
		switch(symbol){
			case '(':
				push(symbol);
				break;
			case ')':
				while((next=pop())!='(')
					postfix[i++]=next;
					break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
					postfix[j++]=pop();
					push(symbol);
				}
					
				push(symbol);
				break;
			default:
				postfix[j++]=symbol;
		}
	}
	while(!isEmpty())
		postfix[j++]=pop();
		
	postfix[j++]='\0';
}		
				

int main()
{
	printf("Enter the infix expression\n");
	gets(infix);
	
	infixToPostfix();
	print();
	return 0;
}