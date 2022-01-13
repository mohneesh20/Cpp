#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n1 = 6;
    int A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5;
    int B[] = {6, 7, 20, 80,40, 100};
    int n3 = 8; 
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    unordered_map<int,bool> umap;
           for(int i=0;i<n1;i++){
               umap[A[i]]=true;
           }
           vector<int> v;
           v.reserve(n1);
           for(int i=0;i<n2;i++){
               if(umap[B[i]]==true){
                   v.push_back(B[i]);
               }
           }
           for(auto itr:v){
               cout<<itr<<" ";
           }
}