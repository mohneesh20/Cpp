#include<iostream>
#include<string>
using namespace std;
int lcs(string s,string t){
    if(s.size()==0||t.size()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }
    int a=lcs(s.substr(1),t);
    int b=lcs(s,t.substr(1));
    int c=lcs(s.substr(1),t.substr(1));
    return max(a,max(b,c));
}
int lcs_mem(string s,string t,int** output){
    int m=s.size();
    int n=t.size();
    if(s.size()==0||t.size()==0){
        return 0;
    }
    int ans;
    if(output[m][n]!=-1){
        return output[m][n];
    }
    if(s[0]==t[0]){
        ans=1+lcs_mem(s.substr(1),t.substr(1),output);
    }
    else{
    int a=lcs_mem(s.substr(1),t,output);
    int b=lcs_mem(s,t.substr(1),output);
    int c=lcs_mem(s.substr(1),t.substr(1),output);
    ans=max(a,max(b,c));
    }
    output[m][n]=ans;
    return ans;
}
int lcs_DP(string a,string b){
    int m=a.size();
    int n=b.size();
    int**output=new int*[a.size()+1];
    for(int i=0;i<=a.size();i++){
        output[i]=new int[b.size()+1];
        // for(int j=0;j<=b.size();j++){
        //     output[i][j]=1;
        // }
    }
    for(int i=0;i<=n;i++){
        output[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        output[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){ 
            if(a[m-i]==b[n-j]){
                output[i][j]=output[i-1][j-1]+1;
            }
            else{
                int a=output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                output[i][j]=max(a,max(b,c));
            }
        } 
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<output[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return output[m][n];
}
int main(){
    string a,b;
    cin>>a>>b;
    int** output=new int*[a.size()+1];
    for(int i=0;i<a.size()+1;i++){
        output[i]=new int[b.size()+1];
        for(int j=0;j<b.size()+1;j++){
            output[i][j]=-1;
        }
    }
    output[0][0]=0;
    cout<<lcs_DP(a,b)<<endl;
    cout<<lcs_mem(a,b,output)<<endl;
}