#include<iostream>
#include<vector>
#include<string>
#include <typeinfo>
using namespace std;
// bool isValid(vector<vector<char>> &board,int row,int col,char num){
//     for(int i=0;i<9;i++){
//         if(board[i][col]==num){
//             return false;
//         }
//         if(board[row][i]==num){
//             return false;
//         }
//         if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num){
//             return false;
//         }
//     }
//     return true;
// }
bool isValid(vector<vector<char>> &board,int y,int x,char num){
    int X=x-1,Y=y;
    while(X>=0){
        if(board[y][X]==num){
            return false;
            break;
        }
        X--;
    }
    X=x+1,Y=y;
    while(X<9){
        if(board[y][X]==num){
            return false;
            break;
        }
        X++;
    }
    X=x,Y=y+1;
    while(Y<9){
        if(board[Y][X]==num){
            return false;
            break;
        }
        Y++;
    }
    X=x,Y=y-1;
    while(Y>=0){
        if(board[Y][X]==num){
            return false;
            break;
        }
        Y--;
    }
    X=x,Y=y;
    for(int i=0;i<9;i++){
        if(board[3*(Y/3)+i/3][3*(X)+(i%3)]==num){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board){
for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        if(solve(board)==true){
                            return true;
                        }
                        else
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solve(board);
    for(auto y:board){
        for(auto x:y){
            cout<<x<<' ';
        }
        cout<<endl;
    }
}