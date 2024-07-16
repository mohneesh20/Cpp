#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool comp(Job a,Job b){
    return a.dead<b.dead;
}
int main(){
Job arr[] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
int n=4;
vector<int> dp(n+1,0);
    sort(arr,arr+n,comp);
    for(int i=1;i<n;i++){
        if(dp[arr[i].dead-1]<arr[i].profit){
            dp[arr[i].dead-1]=arr[i].profit;
        }
    }
    int noOfJobs=0;
    int maxProfit=0;
    for(auto x:dp){
        maxProfit+=x;
        if(x!=0){
            noOfJobs++;
        }
    }
    cout<<maxProfit<<" "<<noOfJobs;
}