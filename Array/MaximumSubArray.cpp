#include<bits/stdc++.h>
using namespace std;


int main(){
   int k=7;
   int n=3;
   int counter=1;
   for(int i=1;i<=n;i++){
    counter*=i;
   }
   k=(counter>k)?k:k-counter;
}