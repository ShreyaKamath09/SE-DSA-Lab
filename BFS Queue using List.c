#include <stdio.h>
#include <stdlib.h>
#define size 10

//int adj[size][size];
int vis[size];
struct ll_node
{
    int vertex;
    struct ll_node* next;
};
struct ll_node* adj[size];
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
            if(adj[p]!=NULL&&vis[adj[p]->vertex]==0)
            {
                enqueue(adj[p]->vertex);
                vis[adj[p]->vertex]=1;
                adj[p]=adj[p]->next;
            }
        }
        p=dequeue();
        if(p!=0)
        {
            printf("%d\t",p);
        }
    }
}

struct ll_node* creategraph(struct ll_node* temp, int x)
{
    struct ll_node* new1=(struct ll_node*)malloc(sizeof(struct ll_node));
    new1->vertex=x;
    new1->next=temp;
    temp=new1;
    return temp;
}
int main()
{
    int nodes,edges,sp,ep,sv,i,j;
    struct ll_node* hp;
    q1.front=q1.rear=-1;

    printf("Hello BFS Queue using List!\n");

    for(i=1;i<=size;i++)
    {
       adj[i]=NULL;
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

        adj[ep]=creategraph(adj[ep],sp);
        adj[sp]=creategraph(adj[sp],ep);
     }

     printf("Adjacency List:\n");

    for(i=1;i<=size;i++)
    {
        hp=adj[i];
        printf("\n");
        while(hp!=NULL)
        {
            printf("%d-->",hp->vertex);
            hp=hp->next;
        }
    }

    printf("\nEnter the source vertex:\n");
    scanf("%d",&sv);

    bfs(sv);

    return 0;
}
