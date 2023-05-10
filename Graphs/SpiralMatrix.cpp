#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<bool>> visit(n,vector<bool>(m,false));
    vector<int> result;
    result.reserve(n*m);
    int i=0,j=0,count=1;
    bool flag1=false;
    bool flag2=false;
    // visit[0][2]=true;
    while(result.size()!=n*m || count!=n*m) {
       
        if(flag1==false && flag2==false){
            if(((j+1)==m)||(visit[i][j+1])){
                flag1=true;
                cout<<i<<" "<<j<<endl;
                i++;
                // break;
                // j--;
                // i++;
                // cout<<endl;
            }
            else{
                cout<<i<<" "<<j<<endl;
                visit[i][j]=true;
                j++;
            }
        }
        if(flag1==true && flag2==false){
            if(((i+1)==n)||(visit[i+1][j])){
                flag1=false;
                flag2=true;
                cout<<i<<" "<<j<<endl;
                j--;
                // i--;
                // j--;
                // cout<<endl;
            }
            else{
                cout<<i<<" "<<j<<endl;
                visit[i][j]=true;
                i++;
            }
        }
        if(flag1==false && flag2==true){
            if(((j-1)<0)||(visit[i][j-1])){
                flag2=true;
                cout<<i<<" "<<j<<endl;
                i--;
                break;
                // j++;
                // i--;
                // cout<<endl;
            }
            else{
                cout<<i<<" "<<j<<endl;
                visit[i][j]=true;
                j--;
            }
        }
        if(flag1==true && flag2==true){
            if(i<0) break;
            if(((i-1)<0)||(visit[i-1][j])){
                flag1=false;
                flag2=false;
                cout<<i<<" "<<j<<endl;
                break;
                // cout<<endl;
            }
            else{
                cout<<i<<" "<<j<<endl;
                visit[i][j]=true;
                i--;
            }
        }
        count++;
    }
}
