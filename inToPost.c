//to convert infix to postfix

#include <stdio.h>
#include <string.h>

char stack[20];
int top = 0;

void push(char item){
    if (top >= 8){
        printf("STACK OVERFLOW");
    } else {
        stack[top] = item;
        top++;
    }
}

char pop(){
    if (top < 0){
        printf("STACK UNDERFLOW");
    } else {
        return stack[top--]; 
    }
}

int count(char string[]){
    int i;
    for (i = 0; string[i]!='\0'; i++){}
    return i;
}

int main(){
    char exp[20],post[20];
    int filled, posted = 0;

    printf("Enter expression to convert: ");
    gets(exp);

    filled = count(exp);

    exp[filled+1] = exp[filled];
    exp[filled] = ')';

    push('(');

    for (int i = 0; i<filled; i++){
        if (exp[i] == '+' || exp[i] == '-'){
            if(stack[top] == '*' || stack[top] == '/' || stack[top] == '+' || stack[top] == '-'){
                int run = 1;
                while (run){
                    if (stack[top] = '('){
                        pop();
                        run = 0;
                    }
                    //post[posted++] = pop();
                    printf("%c",pop());
                }
            }
            push(exp[i]);

        } else if (exp[i] == '*' || exp[i] == '/'){
            if(stack[top] == '+' || stack[top] == '-'){
                int run = 1;
                while (run){
                    if (stack[top] = '('){
                        pop();
                        run = 0;
                    }
                    //post[posted++] = pop();
                    printf("%c",stack[top--]);
                }
            }
            push(exp[i]);
        } else if (exp[i] == ')') {
            int run = 1;
            while (run){
                if (stack[top] = '('){
                    pop();
                    run = 0;
                }
                //post[posted++] = pop();
                printf("%c",stack[top--]);
            }
        } else {
            //post[posted++] = exp[i];
            printf("%c",exp[i]);
        }
    }

    //puts(post);

    return 0;
}