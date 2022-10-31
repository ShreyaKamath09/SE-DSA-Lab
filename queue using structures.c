#include <stdio.h>
#include <stdlib.h>
#define size 5
struct queue
{
    int front,rear;
    int arr[size];
}q;
void enqueue()
{
    int x;
    printf("Enter number to insert:");
    scanf("%d",&x);

    if(q.front==0&&q.rear==size-1 || q.front-1==q.rear)
    {
        printf("Queue Overflow\n");
    }
    else if(q.front==-1)//empty queue insertion
    {
        q.front++;
        q.rear++;
        q.arr[q.front]=x;
    }
    else
    {
        //q.front++;
        q.rear++;
        q.arr[q.rear]=x;
    }
}
void dequeue()
{
    if(q.front==-1)
    {
        printf("Queue Underflow\n");
    }
    else if(q.front==q.rear)//deleting the only element present
    {
        q.front=-1;
        q.rear=-1;
    }
    else
    {
        q.front++;
    }

}
void peek()
{
    printf("Element at front of queue is %d",q.arr[q.front]);

}
void display()
{
    int i;
    for(i=q.front;i<=q.rear;i++)
    {
        printf("%d",q.arr[i]);
    }
}
int main()
{
    int ch;
    q.front=q.rear=-1;

    printf("Hello Queue using structure!\n");
    printf("List of Choices:\n 1.Enqueue\n 2.Dequeue\n 3.Peek\n 4.Display\n 5.Exit\n");

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
                peek();
                break;
            case 4:
                display();
            break;
            case 5:
                printf("EXIT");
                exit(0);
            break;
        }
    }while(ch!=5);

    return 0;
}
