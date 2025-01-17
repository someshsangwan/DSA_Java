//o(N3) space.
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long sum=target-nums[i]-nums[j];
                long long low=j+1;
                long long high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]==sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        s.insert(temp);
                        while (low < high && nums[low] == nums[low+1]) low++;
                        while (low < high && nums[high] == nums[high-1]) high--;
                        
                        low++; high--;
                    }
                    else if(nums[low]+nums[high]<sum){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }