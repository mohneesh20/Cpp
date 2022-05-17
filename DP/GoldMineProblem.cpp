#include<iostream>
#include<vector>
using namespace std;
void getMaxGold(vector<vector<int>> mat,int i,int j,int curGold,int* maxGold,int n){
    if(i<0||i>=mat.size()){
        return;
    }
    if(j==n){
        if(curGold>*maxGold){
            *maxGold=curGold;
        }
        return;
    }
    curGold=curGold+mat[i][j];
    getMaxGold(mat,i,j+1,curGold,maxGold,n);
    getMaxGold(mat,i-1,j+1,curGold,maxGold,n);
    getMaxGold(mat,i+1,j+1,curGold,maxGold,n);
}
int main(){
    vector<vector<int>> mat={{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
    int maxG=0;
    for(int i=0;i<mat.size();i++){
        getMaxGold(mat,i,0,0,&maxG,mat[0].size());
    }
    cout<<"MAX:"<<maxG;
}
