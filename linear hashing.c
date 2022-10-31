#include <stdio.h>
#include <stdlib.h>
#define tablesize 10

int h[tablesize]={NULL};
void insert()
{
    int i,v,value,index,flag=0;

    printf("Enter element to be inserted:");
    scanf("%d",&value);

    v=value%tablesize;
    for(i=0;i<tablesize;i++)
    {
        index=(v+i)%tablesize;

        if(h[index]==NULL)
        {
            h[index]=value;
            break;
        }
    }
    if(i==tablesize)
    {
        printf("Value cannot be inserted.");
    }
}
void search()
{
    int i,v,value,index,flag=0;

    printf("Enter element to be searched:");
    scanf("%d",&value);

    v=value%tablesize;
    for(i=0;i<tablesize;i++)
    {
        index=(v+i)%tablesize;

        if(h[index]==value)
        {
            printf("Element %d is found at index %d.",value,index);
            break;
        }
    }
    if(i==tablesize)
    {
        printf("Value cannot be searched.");
    }
}
void display()
{
    int i;
    printf("Hash table is as follows:\n");
    printf("Index \t\t Value\t\t");
    for(i=0;i<tablesize;i++)
    {
        printf("\n%d \t\t %d\t\t",i,h[i]);
    }
}
int main()
{
    int ch;
    printf("Hello Linear Hashing!\n");
    printf("List of Choices:\n 1.Insert\n 2.Search\n 3.Display\n 4.Exit\n");

    while(1)
    {
        printf("\nEnter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
            break;
            case 2:
                search();
            break;
            case 3:
                display();
                break;
            case 4:
                printf("EXIT");
                exit(0);
            break;
            default:
                printf("Invalid Input");
        }
    }
    return 0;
}
