#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
void snakeAndLadders(vector<vector<int>> &board){
    int n=board.size();
    vector<int> distance(n*n+1,0);
    queue<int> q;
    reverse(board.begin(),board.end());
    int i=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(flag){
            reverse(board[i].begin(),board[i].end());
        }
        flag=!flag;
    }
    q.push(1);
    vector<bool> visited(n*n+1,false);
    // for(int i=0;i<=n*n;i++){
    //         cout<<i<<":"<<visited[i]<<endl;
    // }
    while(q.size()!=0){
        int cur=q.front();
        // cout<<cur<<endl;
        q.pop();
        visited[cur]=true;
        for(int nxt=cur+1;nxt<=cur+6;nxt++){
            if(nxt==n*n){
                break;
            }
            int row=nxt/n;
            int col=nxt%n;
            // cout<<nxt<<" ";
            if(board[row][col]==-1){
                if(distance[nxt]==0) distance[nxt]=distance[cur]+1;
                else distance[nxt]=min(distance[nxt],distance[cur]+1);
                if(visited[nxt]==false){
                    visited[nxt]=true;
                    q.push(nxt);  
                } 
            }
            else{
                if(distance[board[row][col]]==0) distance[board[row][col]]=distance[cur]+1;
                else distance[board[row][col]]=min(distance[board[row][col]],distance[cur]+1);
            }
        }
        for(int i=1;i<=n*n;i++){
            cout<<i<<":"<<distance[i]<<endl;
        }
        cout<<endl;
    }
    // cout<<distance[n*n-1];
    // for(int i=0;i<n*n;i++){
    //     int row=i/n;
    //     int col=i%n;
    //     cout<<i<<":"<<row<<"-"<<col<<endl;
    }
void printBoard(vector<vector<int>>& board){
    int i=0;
    for(auto row:board){
        for(auto col:row){
            cout<<++i<<":"<<col<<"  ";
        }
        cout<<endl<<endl;
    }
}
int main(){
    vector<vector<int>> board = {
    {-1,-1,-1,-1,36,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,28},
    {-1,35,-1,-1,13,-1},
    {-1,-1,-1,-1,-1,28},
    {-1,15,-1,-1,-1,-1},
    };
    snakeAndLadders(board);
    // printBoard(board);
}