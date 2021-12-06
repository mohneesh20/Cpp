#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> answer;
void permute(string s,int str,int lst){
    if(str==lst){
        answer.push_back(s);
        return;
    }
    for(int i=0;i<lst;i++){
        swap(s[str],s[i]);
        permute(s,str+1,lst);
        swap(s[str],s[i]);
    }
}
int main(){
    string s;
    cout<<"Enter String:";
    cin>>s;
    int k;
    cin>>k;
    int len=s.size();
    sort(s.begin(),s.end());
    answer.push_back(s);
    permute(s,0,len);
    cout<<answer[k-1];
}