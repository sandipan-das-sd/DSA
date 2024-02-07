#include<stdio.h>
#include<string.h>
# define N 20
int top=-1;
int stack[N];
void push(int items){
	if(top==N-1){
		printf("Stack is Full");
	}
	else{
		stack[++top]=items;
	}
}
int pop(){
	int del;
	if(top==-1){
		printf("Stack is Empty");	
	}
	else{
		return stack[top--];
	}
}
int evalPostfix(char e[]){
	int i,a;
	for(i=0;i<strlen(e);i++){
		if(e[i]>='0'&&e[i]<='9'){
			push(e[i]-'0');
		}
		else{
			int r,x,y;
			x=pop();
			y=pop();
			switch(e[i]){
				case '+': r=y+x;
				break;
					case '-': r=y-x;
					break;
						case '*': r=y*x;
						break;
							case '/': r=y/x;
							break;
			}
			push(r);
		}
		
	}
		a=pop();
	return a;
}
int main(){
	int x;
	char e[30];
	printf("Enter postfix expression:\n");
	gets(e);
	x= evalPostfix(e);
	printf("Postfix evaluation is:%d",x);
	return 0;
}