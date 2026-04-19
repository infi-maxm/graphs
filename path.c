#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int dfs(int n,int matrix[n+1][n+1],bool visited[],int v,int parent[],int dest){
    visited[v]=true;

    if(v==dest){
        return 1;
    }

    for(int i=1;i<=n;i++){
        if(matrix[v][i]==1 && visited[i]==false){
            parent[i]=v;
            if(dfs(n,matrix,visited,i,parent,dest)){
                return 1;
            }

        }
    }

    return 0;
}

void print_path(int parent[],int v,int dest){
    if(v==dest){
        printf("%d ",v);
        return;
    }

    print_path(parent,v,parent[dest]);
    printf("%d ",dest);
}


int main(){
    int n,e;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter number of edges:");
    scanf("%d",&e);

    int matrix[n+1][n+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrix[i][j]=0;
        }
    }

    int a,b;
    for(int i=0;i<e;i++){
        printf("Enter edge pair (a,b):");
        scanf("%d""%d",&a,&b);

        matrix[a][b]=1;
        matrix[b][a]=1;

    }

    bool visited[n+1];
    int parent[n+1];

    for(int i=1;i<=n;i++){
        visited[i]=false;
        parent[i]=-1;
    }

    printf("Enter source and destination:");
    scanf("%d""%d",&a,&b);

    if(dfs(n,matrix,visited,a,parent,b)){
        printf("Path exists:");
        print_path(parent,a,b);
    }

    return 0;
}