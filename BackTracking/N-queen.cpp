#include<iostream>
#include<vector>
using namespace std;
vector<vector<bool>> markunSafe(vector<vector<bool>> board,int i,int j,int n){
    for(int k=0;k<n;k++){
        board[i][k]=false;
    }
    for(int k=0;k<n;k++){
        board[k][j]=false;
    }
    int X=j,Y=i;
    while(Y<n&&X<n){
        board[Y][X]=false;
        X++;
        Y++;
    }
    X=j,Y=i;
    while(Y>=0&&X>=0){
        board[Y][X]=false;
        X--;
        Y--;
    }
    X=j,Y=i;
    while(Y>=0&&X<n){
        board[Y][X]=false;
        X++;
        Y--;
    }
    X=j,Y=i;
    while(Y<n&&X>=0){
        board[Y][X]=false;
        X--;
        Y++;
    }
    return board;
}
void nQueen(vector<vector<bool>> board,int n,vector<vector<int>> result){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(result.size()==n){
                for(auto x:result){
                    for(auto y:x){
                        cout<<y<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
            return;
            }
            if(board[i][j]==true){
                result.push_back({i,j});
                // cout<<i<<" "<<j<<endl;
                vector<vector<bool>>board2=markunSafe(board,i,j,n);
                // for(auto x:board){
                //     for(auto y:x){
                //         cout<<y<<" ";
                //         }
                //     cout<<endl;
                // }
                // cout<<endl;
                nQueen(board2,n,result);
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of board:";
    cin>>n;
    vector<vector<bool>> board(n,vector<bool>(n,true));
    vector<vector<int>> result;
    // board=markunSafe(board,0,0,n);
    // // board=markunSafe(board,1,2,n);
    // for(auto x:board){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //    cout<<endl;
    // }
    nQueen(board,n,result);
}