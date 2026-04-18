#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node*next;
}node;

void add_edge(node*arr[],int a,int b){
    node*newn=(node*)malloc(sizeof(newn));
    newn->data=b;
    newn->next=arr[a];
    arr[a]=newn;
}

void bfs(node*arr[],int n,int v,int w){
    bool visited[n+1];

    for(int i=1;i<=n;i++){
        visited[i]=false;
    }

    int queue[n],distance[n+1];
    int front=0,rear=0;
    queue[rear]=v;
    rear++;
    distance[v]=0;

    while(front<rear){
        int r=queue[front++];

        if(r==w){
            printf("Distance of %d from %d :%d",w,v,distance[w]);
            break;
        }

        node*temp=arr[r];
        while(temp!=NULL){
            if(visited[temp->data]==false){
                visited[temp->data]=true;
                queue[rear++]=temp->data;
                distance[temp->data]=distance[r]+1;
            }

            temp=temp->next;
        }
    }
}

int main(){
    int n,e;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter number of edges:");
    scanf("%d",&e);

    node*arr[n+1];

    for(int i=1;i<=n;i++){
        arr[i]=NULL;
    }

    int a,b;
    for(int i=0;i<e;i++){
        printf("Enter the edge pair(a,b):");
        scanf("%d%d",&a,&b);
        add_edge(arr,a,b);
    }
    int v,w;
    printf("Enter starting user vertex:");
    scanf("%d",&v);
    printf("Enter user2 vertex:");
    scanf("%d",&w);
    printf("\nanswer:");
    bfs(arr,n,v,w);
    return 0;
}