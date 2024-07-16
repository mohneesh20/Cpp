#include <iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
bool hasString(vector<vector<char>> mat,bool** visited,string word,int XIndex,int YIndex){
    if(word.size()==0){
        return true;
    }
    vector<int> y={0,1,1,1,0,-1,-1,-1};
    vector<int> x={1,1,0,-1,-1,-1,0,1};
    for(int i=0;i<8;i++){
        int xIndex=XIndex+x[i];
        int yIndex=YIndex+y[i];
        if(xIndex<0||xIndex==mat[0].size()){
            continue;
        }
        if(yIndex<0||yIndex==mat.size()){
            continue;
        }
        if(word[0]==mat[yIndex][xIndex]&&visited[yIndex][xIndex]==false){
            visited[yIndex][xIndex]=true;
            bool flag=hasString(mat,visited,word.substr(1),xIndex,yIndex);
            if(flag){
                return flag;
            }
            else{
                visited[yIndex][xIndex]=false;
            }
        }
    }
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            cin>>tmp;
            mat[i].push_back(tmp);
        }
    }
    string word;
    cin>>word;
    vector<vector<int>> c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==word[0]){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                c.push_back(tmp);
            }
        }
    }
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }
    for(int i=0;i<c.size();i++){
        visited[c[i][0]][c[i][1]]=true;
        bool result=hasString(mat,visited,word.substr(1),c[i][1],c[i][0]);
        if(result){
            cout<<"C at:"<<c[i][0]<<","<<c[i][1]<<endl;
            cout<<"STRING FOUND:"<<word;
            break;
        }
        else{
            cout<<"STRING NOT FOUND"<<endl;
        }
    }
}
