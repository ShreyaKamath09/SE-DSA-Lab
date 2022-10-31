#include <stdio.h>
#include <stdlib.h>
#define size 10

int adj[size][size];
int vis[size];

struct queue
{
    int a[size];
    int front,rear;
}q1;

void enqueue(int x)
{
   if(q1.front==-1)
   {
       q1.front++;
       q1.rear++;
       q1.a[q1.front]=x;
       return;
   }
   q1.rear++;
   q1.a[q1.rear]=x;
   return;
}

int dequeue()
{
    int t;
    t=q1.a[q1.front];
    q1.front++;
    return t;
}

void bfs(int s)
{
    int p;
    enqueue(s);
    vis[s]=1;
    p=dequeue();

    if(p!=0)
    {
        printf("%d\t",p);
    }
    while(p!=0)
    {
        for(int i=1;i<=size;i++)
        {
            if(adj[p][i]==1&&vis[i]==0)
            {
                enqueue(i);
                vis[i]=1;
            }
        }
        p=dequeue();
        if(p!=0)
        {
            printf("%d\t",p);
        }
    }
}
int main()
{
    int nodes,edges,sp,ep,sv,i,j;
    q1.front=q1.rear=-1;

    printf("Hello BFS Queue using Matrix!\n");

    for(i=1;i<=size;i++)
    {
        for(j=1;j<=size;j++)
        {
            adj[i][j]=0;
        }
    }

     for(i=1;i<size;i++)
     {
        vis[i]=0;
     }

     printf("Enter number of nodes:");
     scanf("%d",&nodes);
     printf("Enter number of edges:");
     scanf("%d",&edges);

     for(i=1;i<=edges;i++)
     {
        printf("\nEnter the start point:");
        scanf("%d",&sp);
        printf("Enter the end point:");
        scanf("%d",&ep);

        adj[ep][sp]=1;
        adj[sp][ep]=1;
     }

     printf("Adjacency Matrix:\n");

    for(i=1;i<=size;i++)
    {
        printf("\n");
        for(j=1;j<=size;j++)
        {
            printf("%d\t",adj[i][j]);
        }
    }

    printf("\nEnter the source vertex:\n");
    scanf("%d",&sv);

    bfs(sv);

    return 0;
}
