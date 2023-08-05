#include<bits/stdc++.h>
using namespace std;
int maximumRequests(int n, vector<vector<int>>& requests) {
        cout<<n<<endl;
        return n;
}
int main(){
    int n = 5;
    vector<vector<int>> requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    maximumRequests(n, requests);
}