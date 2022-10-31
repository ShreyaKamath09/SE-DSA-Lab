#include <stdio.h>
#include <stdlib.h>
//shreya
void insertion()
{
    int i,j,low,n,temp;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++)
    {
        printf("Enter Element:");
        scanf("%d",&a[i]);
    }

    for(i=1;i<n;i++)
    {
        low=a[i];
        //j=i-1;

        for(j=i;j>0 && low<a[j-1];j--)
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            //j=j-1;
        }
         display(a,n);
        a[j]=low;
    }

}
void selection()
{
    int i,j,min,n,temp;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++)
    {
        printf("Enter Element:");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
         display(a,n);

       for(j=1+i;j<n+1;j++)
       {
         if(a[i]>a[j])
         {

            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
       }

    }

}
void display(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int main()
{
    int ch;
    printf("Hello Insertion and Selection Sort!\n");
    printf("List of Choices:\n 1.Insertion Sort\n 2.Selection Sort\n 3.Exit\n");
    do{

    printf("\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        insertion();
        break;
    case 2:
        selection();
        break;
    case 3:
        printf("EXIT");
        exit(0);
    default:
        printf("Invalid Input");
    }

    }while(ch!=3);
    return 0;
}
