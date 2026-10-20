
#include <stdio.h>
#include <ctype.h>

int st[100],top=-1;

void push(int x)
{
    st[++top]=x;
}

int pop()
{
    return st[top--];
}

int evaluate(char exp[])
{
    int i,a,b;
    top=-1;
    for(i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])) push(exp[i]-'0');
        else{
            b=pop(); a=pop();
            if(exp[i]=='+') push(a+b);
            else if(exp[i]=='-') push(a-b);
            else if(exp[i]=='*') push(a*b);
            else if(exp[i]=='/') push(a/b);
        }
    }
    return pop();
}

int main()
{
    char exp[100];
    printf("Enter postfix: ");
    scanf("%99s",exp);
    printf("Result=%d\n",evaluate(exp));
    return 0;
}
