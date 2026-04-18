#include<stdio.h>
#include<stdlib.h>

void topo(int n,int matrix[n+1][n+1]){
    int indegree[n+1];
    for(int i=1;i<=n;i++){
        indegree[i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i][j]==1){
                indegree[j]++;
            }
        }
    }

    int queue[n+1];
    int front=0,rear=0;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            queue[rear++]=i;
        }
    }

    int count=0;
    while(front<rear){
        int r=queue[front++];
        printf("%d ",r);
        count++;

        for(int i=1;i<=n;i++){
            if(matrix[r][i]==1){
                indegree[i]--;
                if(indegree[i]==0){
                    queue[rear++]=i;
                }
            }
        }
    }

    if(count==n){
        printf("\nNo cycle");
    }else{
        printf("\nYes cycle");
    }


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
        printf("Enter edge pair:");
        scanf("%d%d",&a,&b);
        matrix[a][b]=1;
    }

    printf("Topo sort:");
    topo(n,matrix);

    return 0;

    
}