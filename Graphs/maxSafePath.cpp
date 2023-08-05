#include<bits/stdc++.h>
using namespace std;
class container{
    public:
        int x=0;
        int y=0;
        int len=0;
        container(int X,int Y):x(X),y(Y),len(1){}
        container(int X,int Y,int l):x(X),y(Y),len(l){}
};
vector<int> X={1,1,0,-1,-1,-1,0,1};
vector<int> Y={0,1,1,1,0,-1,-1,-1};
int shortestBinaryPath(vector<vector<int>> &grid){
    if(grid[0][0]==1) return -1;
    queue<container*> q;
    int n=grid.size();
    vector<vector<bool>> visit(n,vector<bool>(n,false));
    container* start_node=new container(0,0);
    q.push(start_node);
    while(q.size()!=0){
        container* node=q.front();
        q.pop();
        if((node->x==n-1)&&(node->y==n-1)){
            return node->len;
        }
        visit[0][0]=true;
        for(int i=0;i<8;i++){
            int cX=node->x+X[i];
            int cY=node->y+Y[i];
            if((cX>=0&&cX<n)&&(cY>=0&&cY<n)&&(grid[cY][cX]==0)&&(visit[cY][cX]==false)){
                container* child_node=new container(cX,cY,node->len+1);
                visit[cY][cX]=true;
                q.push(child_node);
                cout<<child_node->y<<" "<<child_node->x<<" "<<child_node->len<<endl;
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> grid={{1,0,0},{1,1,0},{0,0,0}};
    cout<<shortestBinaryPath(grid)<<endl;
}