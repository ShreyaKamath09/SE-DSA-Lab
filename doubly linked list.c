#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
    int data;
    struct ll_node* next;
    struct ll_node* prev;
};
struct ll_node* list;
struct ll_node* insert(struct ll_node* list)
{
    int value;
    struct ll_node* help_ptr=list;

    struct ll_node* pnew=(struct ll_node*)malloc(sizeof(struct ll_node));

    if(pnew!=NULL)
    {

       printf("Enter value to be inserted:");
       scanf("%d",&value);

        pnew->data=value;
        pnew->next=NULL;
        pnew->prev=NULL;


    if(list==NULL)
    {
        list=pnew;

        return list;
    }
     if(list->data>=value)
     {
         pnew->next=list;
         list->prev=pnew;
         list=pnew;
         return list;
     }
    while(help_ptr->next!=NULL && help_ptr->next->data<value)
    {
        help_ptr=help_ptr->next;

    }
    while(help_ptr->next!=NULL)
    {
        help_ptr->next->prev=pnew;
    }
    pnew->next=help_ptr->next;
    help_ptr->next=pnew;

    return list;
    }
    return list;

}
struct ll_node* delete1(struct ll_node* list)
{
    int target;
    printf("Enter value to be deleted:");
    scanf("%d",&target);

    struct ll_node* help_ptr=list;
    struct ll_node* n2d;
    if(help_ptr->data==target)
    {
        list=help_ptr->next;
        list->prev=NULL;
        free(help_ptr);
        return list;
    }
    while(help_ptr->next!=NULL)
    {
        if(help_ptr->next->data==target)
        {
            n2d=help_ptr->next;
            help_ptr->next=n2d->next;
            if(n2d->next!=NULL)
            {
                n2d->next->prev=help_ptr;
            }
            free(n2d);
            return list;
        }
        help_ptr=help_ptr->next;
    }
}
void display()
{
    struct ll_node* help_ptr=list;
    if(list==NULL)
    {
        printf("List is Empty\n");
    }
   while(help_ptr!=NULL)
   {
       printf("\t%d-->",help_ptr->data);
       help_ptr=help_ptr->next;
   }
}
int main()
{
    int ch;
    list=NULL;
    printf("Hello Doubly Linked List!\n");
    printf("List of Choices:\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");

    while(1)
    {
        printf("\nEnter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                list=insert(list);
            break;
            case 2:
                list=delete1(list);
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
