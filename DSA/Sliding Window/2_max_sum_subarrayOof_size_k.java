//problem - given an array , and an inteeger K fidd the max sum of subarray of size K;
// int arr[]={2,5,1,8,2,9,1}; k=3;
// 2+5+1=8,5+1+8=14,1+8+2=11,8+2+9=19,2+9+1=12  output will be =19;
// int arr[]=[ , ,i, , ,j , ] window size will be j-i+1;
class Solution {
    public int maximumSumSubarray(int[] arr, int k) {
        int n=arr.length;
        int i=0;
        int j=0;
        int res=0;
        int sum=0;
        while(j<n){
            sum=sum+arr[j];
            if(j-i+1<k){
                j++;
            }
            else{
                res=Math.max(res,sum);
                sum=sum-arr[i];
                i++;
                j++;
            }
        }
        return res;
        
        
    }
}