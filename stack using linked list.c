#include <stdio.h>
#include <stdlib.h>
#define size 5
struct ll_node
{
    int data;
    struct ll_node* next;
};
struct ll_node* top;
void push()
{
    struct ll_node* pnew = (struct ll_node*)malloc(sizeof(struct ll_node));

        int a;
        printf("Enter element you want to push:\n");
        scanf("%d",&a);

        pnew->data=a;

        if(top==NULL)
        {
            pnew->next=NULL;
        }

            pnew->next=top;
            top=pnew;

        return;
}
void pop()
{
    struct ll_node* n2d=top;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
    }

        printf("Element %d has been popped\n",top);
        n2d->data=top->data;
        top=top->next;
        free(n2d);
        return;

}
void display()
{
    struct ll_node* help_ptr=top;
    while(top!=NULL)
    {
        printf("%d\n",help_ptr->data);
        help_ptr=help_ptr->next;
    }
    return;
}
int main()
{
    top=NULL;
    int ch;
    printf("Hello Stacks using Linked List!\n");
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
