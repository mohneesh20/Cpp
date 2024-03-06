#include<bits/stdc++.h>
using namespace std;
//[1,3,4,2,2]
//[3,1,3,4,2]
int findDup(vector<int> nums){
        int slow=nums[0];
        int fast=nums[0];
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
}
int main(){
    vector<int> arr={};
    findDup(arr);
}