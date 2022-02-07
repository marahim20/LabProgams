#include <stdio.h>
void display(int q[10]);
void push(int q[10]);
void pop(int q[10]);
int top = -1, n;
int main(){
    int k, a;
    printf("Enter the number of elements you want to enter in the stack\n");
    scanf("%d", &n);
    int stack[n];
    do{
        printf("\n1.Push\n2.Pop\n3.Display\n");
        scanf("%d", &k);
        switch(k){
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\nDo you want to continue?\n1.Yes\n2.No\n");
        scanf("%d", &a);
    }while(a == 1);
}
void push(int q[10]){
    int item;
    top++;
    if(top == n){
        printf("Stack is full\n");
        top--;
    }
    else{
        printf("Enter the element to be pushed\n");
        scanf("%d", &q[top]);
    }
}
void pop(int q[10]){
    if(top == -1){
        printf("Stack is empty\n");
        top++;
    }
    else{
        printf("The element popped is %d\n", q[top]);
        top--;
    }
}
void display(int q[10]){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("The elements in the stack are\n");
        for(int i = top; i >= 0; i--){
            printf("%d\n", q[i]);
        }
    }
}