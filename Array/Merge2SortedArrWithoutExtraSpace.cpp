#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<int> arr1= {1, 3, 5, 7};
  vector<int> arr2= {0, 2, 6, 8, 9};
  int n=arr1.size();
  int m=arr2.size();
  sort(arr1.begin(),arr1.end());
  sort(arr2.begin(),arr2.end());
  
}
