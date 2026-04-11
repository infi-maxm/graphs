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
  
void dfs(int n,node*arr[],int v,bool visited[]){
    visited[v]=true;
    printf("%d ",v);
    node*temp=arr[v];
    while(temp!=NULL){
        if(visited[temp->data]==false){
            dfs(n,arr,temp->data,visited);
        }
        temp=temp->next;
    }

}

void bfs(int n,node*arr[],int v){
    bool visited[n+1];

    for(int i=1;i<=n;i++){
        visited[i]=false;
    }

    int queue[n+1];
    int front=0,rear=0;
    visited[v]=true;
    queue[rear]=v;
    rear++;
    
    while(front<rear){
        int r=queue[front++];
        printf("%d ",r);

        node*temp=arr[v];
        while(temp!=NULL){
            if(visited[temp->data]==false){
                rear++;
                queue[rear]=temp->data;
                visited[temp->data]=true;
            }
            
            temp=temp->next;
        }
    }


}

int main(){
    int n,e,a,b;
    printf("Enter the number of vertices:");
    scanf("%d",&n);

    //creating an array of pointers
    node*arr[n+1];

    for(int i=1;i<=n;i++){
        arr[i]=NULL;
    }

    printf("Enter the number of edges:");
    scanf("%d",&e);

    for(int i=1;i<=n;i++){
        printf("Enter the vertices forming edge:");
        scanf("%d""%d",&a,&b);
        add_edge(arr,a,b);
    }

    bool visited[n+1];

    for(int i=1;i<=n;i++){
        visited[i]=false;
    }

}