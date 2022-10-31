#include <stdio.h>
#include <stdlib.h>
#define size 5
struct stack
{
    int top;
    int arr[size]
}s1;
void push()
{
    if(s1.top==size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int a;
        printf("Enter element you want to push:\n");
        scanf("%d",&a);
        s1.top++;
        s1.arr[s1.top]= a;
    }
}
void pop()
{
    if(s1.top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Element %d has been popped\n",s1.arr[s1.top]);
        s1.top--;
    }
}
void display()
{
    int i;
    for(i=s1.top;i>=0;i--)
    {
        printf("%d\n",s1.arr[i]);
    }
}
int main()
{
    s1.top=-1;
    int ch;
    printf("Hello Stacks using arrays!\n");
    printf("List of Choices:\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
    do
    {
        printf("Enter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
            break;
            case 2:
                pop();
            break;
            case 3:
                display();
            break;
            case 4:
                printf("EXIT");
                exit(0);
            break;
        }
    }while(ch!=4);

    return 0;
}
