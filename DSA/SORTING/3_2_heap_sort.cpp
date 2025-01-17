#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// heapify function is used to create a max heap;
// heapsort - is used to sort an array in ascending order -o(nlogn) time complexity;
// in heapsort first we convert array into heap now swap first element of array with last array bcz first element wiil be 
// max element bcz of heap now remove last elememt from heap now again convert array into heap and same process--


class Solution {
public:
    void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest] ){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest !=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums;
    }
};