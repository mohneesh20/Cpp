#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr1={9,11,19,26,32,34,45,50,56,58,61,88};
    vector<int> arr2={1,5,5,7,9,9,11,13,13,15,18,19,19,20,21,28,28,28,29,29,30,31,39,40,44,47,47,50,52,56,57,61,61,61,66,68,69,70,70,74,75,75,77,78,79,80,82,85,87,89,90,90,90,92,93,95,97,98,98,100};
    int n=arr1.size();
    int m=arr2.size();
    vector<int> arr3;
    int i=0,j=0;
    while(i<n&j<m){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i++]);
        }
        else{
            arr3.push_back(arr2[j++]);
        }
    }
    while(i<n){
        arr3.push_back(arr1[i++]);
    }
    while(j<m){
        arr3.push_back(arr2[j++]);
    }
    // cout<<i<<" "<<j<<" "<<arr3.size();
    // cout<<n<<" "<<m<<" "<<arr3.size();
    for(int k=0;k<arr3.size();k++){
        cout<<k+1<<":"<<arr3[k]<<"  ";
    }
}