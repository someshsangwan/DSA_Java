#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        ans.push_back({arr[0][0],arr[0][1]});
        for(int i=1;i<n;i++){
            int size=ans.size();
            if(ans[size-1][1]>=arr[i][0]){
                ans[size-1][0]=min(ans[size-1][0],arr[i][0]);
                ans[size-1][1]=max(ans[size-1][1],arr[i][1]);
            }
            else{
                ans.push_back({arr[i][0],arr[i][1]});
            }
        }
        return ans;
    }