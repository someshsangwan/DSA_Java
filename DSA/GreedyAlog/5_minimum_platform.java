package GreedyAlog;

import java.util.*;
class Solution {
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    
    static int findPlatform(int arr[], int dep[]) {
        Arrays.sort(arr);
        Arrays.sort(dep);
        int i=0;
        int j=0;
        int n=arr.length;
        int res=0;
        int platform=0;
        while(i<n &&j<n){
            if(arr[i]<=dep[j]){
                i++;
                platform++;
            }
            else{
                platform--;
                j++;
            }
            res=Math.max(res,platform);
        }
        return res;
    }
}
