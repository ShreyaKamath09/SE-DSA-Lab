#include <stdio.h>
#include <stdlib.h>
struct ll_node
{
    int data;
    struct ll_node* next;
};
struct ll_node* front;
struct ll_node* rear;

void enqueue()
{
    struct ll_node* pnew=(struct ll_node*)malloc(sizeof(struct ll_node));

    int value;
    printf("Enter value to insert:");
    scanf("%d",&value);

    pnew->data=value;
    pnew->next=NULL;

    if(front==NULL)
    {
        front=pnew;
        rear=pnew;
        return;
    }
    rear->next=pnew;
    rear=pnew;
    return;

}
void dequeue()
{
    struct ll_node* n2d;
    printf("Element %d has been de-queued.\n",front->data);
    if(front==NULL)
    {
       printf("Queue Underflow");
    }
    else if(front==rear)
    {
      free(front);
      front=rear=NULL;
    }
    n2d=front;
    front=front->next;
    free(n2d);

    return;
}
void display()
{
     struct ll_node* help_ptr=front;
     if(front==NULL)
     {
         printf("Queue Underflow");
     }
     else
     {
         while(help_ptr!=NULL)
         {
             printf("%d\t",help_ptr->data);
             help_ptr=help_ptr->next;
         }
     }
}
int main()
{
    int ch;
    front=rear=NULL;
    printf("Hello Queue using Linked List!\n");
    printf("List of Choices:\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");

    do
    {
        printf("\nEnter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
            break;
            case 2:
                dequeue();
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
