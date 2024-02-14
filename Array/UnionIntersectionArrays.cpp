#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a={1,2,3,4,6};
    vector<int> b={2,3,5};
    int i=0,j=0;
    vector<int> result;
    int n=a.size();
    int m=b.size();
    result.reserve(n+m);
    while(i!=n&&j!=m){
        if(a[i]!=b[j]){
            if(a[i]<b[j]){
                result.emplace_back(a[i]);
                int tmp=a[i];
                while(a[i]==tmp){
                    i++;
                    if(i==n) break;
                }
            }else{
                result.emplace_back(b[j]);
                int tmp=b[j];
                while(b[j]==tmp){
                    j++;
                    if(j==m) break;
                }
            }
        }else{
            int tmp=a[i];
            result.emplace_back(tmp);
            while(a[i]==tmp){
                i++;
                if(i==n) break;
            }
            while(b[j]==tmp){
                j++;
                if(j==m) break;
            }
        }
    }
    while(i!=n){
        int tmp=a[i];
        result.emplace_back(tmp);
        while(a[i]==tmp){
            i++;
            if(i==n) break;
        }
    }
    while(j!=m){
        int tmp=b[j];
        result.emplace_back(tmp);
        while(b[j]==tmp){
            j++;
            if(j==m) break;
        }
    }
    for(auto &itr:result){
        cout<<itr<<" ";
    }
}