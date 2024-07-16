#include <iostream>
#include<math.h>
#include<vector>
using namespace std;
int minCostPath_DP(int** matrix,int m,int n){
    int **output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
    }
    output[m-1][n-1]=matrix[m-1][n-1];
    for(int i=n-2;i>=0;i--){
        output[m-1][i]=output[m-1][i+1]+matrix[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1]+matrix[i][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=matrix[i][j]+min(output[i+1][j],min(output[i+1][j+1],output[i][j+1]));

        }
    }
    return output[0][0];
}
int minCostPath_mem(int** input,int m,int n,int i,int j,int** output){
    if(i==m-1&&j==n-1){
        return input[i][j];
    }
    if(i>=m||j>=n){
        return INT32_MAX;
    }
    if(output[i][j]!=-1){
        return output[i][j];
    }
    int x=minCostPath_mem(input,m,n,i,j+1,output);
    int y=minCostPath_mem(input,m,n,i+1,j+1,output);
    int z=minCostPath_mem(input,m,n,i+1,j,output);
    int ans=min(x,min(y,z))+input[i][j];
    output[i][j]=ans;
    return ans;
}
int main() {
    int n,m;
    cin>>m>>n;
    int** matrix=new int*[n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    // int**output=new int*[m];
    // for(int i=0;i<n;i++){
    //     output[i]=new int[m];
    //     for(int j=0;j<m;j++){
    //         output[i][j]=-1;
    //     }
    // }
    int result=minCostPath_DP(matrix,m,n);
    cout<<result;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
