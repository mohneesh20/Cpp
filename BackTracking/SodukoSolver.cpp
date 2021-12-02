#include<iostream>
#include<vector>
#include<string>
#include <typeinfo>
using namespace std;
bool isValid(vector<vector<string>> &board,int row,int col,string num){
    for(int i=0;i<9;i++){
        if(board[i][col]==num){
            return false;
        }
        if(board[row][i]==num){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num){
            return false;
        }
    }
    return true;
}
bool sudokuSolver(vector<vector<string>> &board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!="."){
                continue;
            }
            else{
                for(int k=1;k<10;k++){
                    string number=to_string(k);
                    if(isValid(board,i,j,number)){
                        board[i][j]=number;
                        if(sudokuSolver(board)){
                            return true;
                        }
                        else{
                            board[i][j]=".";
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<string>> board={{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    sudokuSolver(board);
    for(auto y:board){
        for(auto x:y){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}