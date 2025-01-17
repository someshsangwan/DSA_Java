 
// probelm is that
// Given N activities with their start and finish day given in array start[ ] and end[ ]. 
// Select the maximum number of activities that can be performed by a single person, 
// assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.
// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation: (1,2) , (3,4) ,(2,3) ,(5,6);  isme se konse interval overlap nhi ho rhe h dekho bhaiay
// A person can perform activities 1, 2
// and 4.

// greedy - sorting lgti h isme jyadater yad rakhna mere bache ;
// sort array according to finish time;
#include<bits/stdc++.h>
using namespace std;
#include<iostream>

// probelm is that
// Given N activities with their start and finish day given in array start[ ] and end[ ]. 
// Select the maximum number of activities that can be performed by a single person, 
// assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.
// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation: (1,2) , (3,4) ,(2,3) ,(5,6);  isme se konse interval overlap nhi ho rhe h dekho bhaiay
// A person can perform activities 1, 2
// and 4.

// greedy - sorting lgti h isme jyadater yad rakhna mere bache ;
// sort array according to finish time;
    bool static comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int res=1;
        int prev=0;
        for(int i=1;i<n;i++){
            if(v[i].first>=v[prev].second){
                res++;
                prev=i;
            }
            
        }
        return res;
        
    }
