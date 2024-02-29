#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                if(nums[i]<0){
                    int tmp=nums[i];
                    int j=i;
                    while(j!=n&&tmp<0){
                        int tmp2=nums[j+1];
                        nums[j+1]=tmp;
                        tmp=tmp2;
                    }
                    nums[i]=tmp;
                }
            }else{
                if(nums[i]>0){
                    int tmp=nums[i];
                    int j=i; 
                    while(j!=n&&tmp>0){
                        int tmp2=nums[j+1];
                        nums[j+1]=tmp;
                        tmp=tmp2;
                    }
                    nums[i]=tmp;
                }
            }
        }
        return nums;
}


    