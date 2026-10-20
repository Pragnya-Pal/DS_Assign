#include <stdio.h>
#include <string.h>
char stack[20];
int top = -1;


void infix_to_postfix (char infix[20]);
void postfix_to_infix (char postfix[20]);

int main (){
    char infix [20];
    char postfix [20];
    printf ("Enter Infix Expression: ");
    scanf ("%s", infix);
     printf ("\n\nEnter Postfix Expression: ");
    scanf ("%s", postfix);
    return 0;
}

int precedence (char op){
    if (op=='(') return 0;
    else if (op =='+'||op == '-') return 1;
    else if (op == '*'||op=='/') return 2;
    else if (op =='^') return 3;
    else return -1;
}

void push (char ch){
    top++;
    stack[top] = ch;
}

char pop(){
    char t = stack [top];
    top--;
    return (t);
}


void infix_to_postfix (char infix[20]){
    char postfix[20];
    int k=0;
    char ch;
    for (int i=0; infix[i]!='\0'; i++){
        if (infix[i]=='(') push ('(');
        else if (infix[i] == ')'){
            while (ch=pop()!='(') {
                postfix [k] = ch; k++;
            }
        }
        else if (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'){
            while (ISP(stack[top]) >= ICP(infix[i])){
                postfix[k] = pop();
                k++;}
            push (infix[i]);
        }
        else {
            postfix[k] = infix[i]; k++;
        }
    }
    while (top != -1){
        postfix [k] = pop(); k++;
    }
    postfix [k] = '\0'; printf ("%s", postfix);
}


void postfix_to_infix (char postfix[20]){
    char stack[20][20];
    int top = -1;
    
    for (int i = 0; postfix[i] != '\0'; i++){
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
            char op1[20], op2[20], temp[20];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            strcpy(stack[++top], temp);
        }
        else {
            char temp[2] = {postfix[i], '\0'};
            strcpy(stack[++top], temp);
        }
    }
    printf ("%s", stack[top]);
}

