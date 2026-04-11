#include<stdio.h>
#include<stdbool.h>

void dfs(int n,int matrix[n+1][n+1],int v,bool visited[]){
  visited[v]=true;
  printf("%d ",v);
  for(int i=1;i<=n;i++){
    if(matrix[v][i]==1 && visited[i]==false){
         dfs(n,matrix,i,visited);
    }
  }

}


void bfs(int n,int matrix[n+1][n+1],int v){
   bool visited[n+1];
   for(int i=1;i<=n;i++){
        visited[i]=false;
    }
   visited[v]=true;
   int queue[n+1];
   int front=0,rear=0;
   queue[rear]=v;
   rear++;

    while(front<rear){
        int r=queue[front++];
        printf("%d ",r);

        for(int i=1;i<=n;i++){
            if(visited[i]==false && matrix[r][i]==1){
                visited[i]=true;
                queue[rear++]=i;
            }
        }
    }
} 


int main(){
    int n,e;
    printf("Enter number of vertices:");
    scanf("%d",&n);

    int matrix[n+1][n+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrix[i][j]=0;
        }
    }

    printf("Enter number of edges:");
    scanf("%d",&e);

    for(int i=0;i<e;i++){
        int a,b;
        printf("Enter vertices forming edge a,b:");
        scanf("%d%d",&a,&b);
        matrix[a][b]=1;
    }

    bool visited[n+1];

    for(int i=1;i<=n;i++){
        visited[i]=false;
    }

    dfs(n,matrix,1,visited);
    printf("\nbfs:");
    bfs(n,matrix,1);

 
}