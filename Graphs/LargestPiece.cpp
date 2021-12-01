#include <iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int sizePiece(vector<vector<bool>> matrix,bool** visited,int YI,int XI){
    int sum=0,tmp=0;
    vector<int> y={0,1,0,-1};
    vector<int> x={1,0,-1,0};
    for(int i=0;i<4;i++){
        int xi=XI+x[i];
        int yi=YI+y[i];
        if(xi<0||xi==matrix[0].size()){
            continue;
        }
        if(yi<0||yi==matrix.size()){
            continue;
        }
        if(matrix[yi][xi]==true&&visited[yi][xi]==false){
            visited[yi][xi]=true;
            tmp=sizePiece(matrix,visited,yi,xi);
            sum=tmp+sum;
        }
    }
    return sum+1;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> mat(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool tmp;
            cin>>tmp;
            mat[i].push_back(tmp);
        }
    }
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }
    // for(int i=0;i<n;i++){
    //     // visited[i]=new bool[m];
    //     for(int j=0;j<m;j++){
    //         // visited[i][j]=false;
    //         cout<<mat[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false&&mat[i][j]==true){
                visited[i][j]=true;
                int sum=sizePiece(mat,visited,i,j);
                if(max<sum){
                    max=sum;
                }
            }
        }
    }
    cout<<"MAX:"<<max;
    for(int i=0;i<n;i++){
        delete [] visited[i];
    }
    delete [] visited;
}
