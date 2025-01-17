using namespace std;
#include <bits/stdc++.h>
#include <iostream>

// brute force - hr index ka check krenge kitna pani store kr skta h;
// store[i]=min(leftmax[i],rightmax[i])-arr[i]; //time o(n) && space o(n);
int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix_sum(n,height[0]);
        int res=height[0];
        for(int i=1;i<n;i++){
            if(height[i]>res){
                res=height[i];
            }
            prefix_sum[i]=res;
        }
        vector<int>suffix_sum(n,height[n-1]);
        int res1=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(height[i]>res1){
                res1=height[i];
            }
            suffix_sum[i]=res1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(suffix_sum[i],prefix_sum[i]);
            ans+=x-height[i];
        }
        return ans;
        
    }
// optimised solution;
// 2 pointer approach ;
     int trap(vector<int>& height) {
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            if(maxleft<height[left]){
                maxleft=height[left];
            }            
            if(maxright<height[right]){
                maxright=height[right];
            }
            if(maxleft<maxright){
                res=res+maxleft-height[left];
                left++;
            }
            else{
                res=res+maxright-height[right];
                right--;
            }
 
        }
        return res;

    }