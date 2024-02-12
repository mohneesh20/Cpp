#include<bits/stdc++.h>
using namespace std;

vector<int> Union(vector<int> arr1, vector<int> arr2){
    int i=0;
    int j=0;
    vector<int> result;
    while(i!=arr1.size() && j!=arr2.size()){
        if(arr1[i]==arr2[j]){
            result.emplace_back(arr1[i]);
            int tmp = arr1[i];
            while(arr1[i]==tmp) i++;
            while(arr2[j]==tmp) j++;
        }else{
            result.emplace_back(min(arr1[i],arr2[j]));
            if(arr1[i]<arr2[j]){
                int tmp = arr1[i];
                while(arr1[i]==tmp) i++;
            }else{
                int tmp = arr2[j];
                while(arr2[j]==tmp) j++;
            }
        }
    }
    while(i!=arr1.size()){
        int tmp=arr1[i];
        result.emplace_back(tmp);
        while(arr1[i]==tmp) i++;
    }
    while(j!=arr2.size()){
        int tmp=arr1[j];
        result.emplace_back(tmp);
        while(arr2[j]==tmp) j++;
    }
    return result;
}
int main(){
    vector<int> arr1={1,2,3,3};
    vector<int> arr2={2,3,4};
    vector<int> union_arr=Union(arr1, arr2);
    cout<<union_arr.size();
    // for(auto &itr:union_arr){
    //     cout<<itr<<" ";
    // }
}