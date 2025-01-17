// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output: 
// 3 3 4 5 5 5 6 
// Explanation: 
// 1st contiguous subarray = {1 2 3} Max = 3
// 2nd contiguous subarray = {2 3 1} Max = 3
// 3rd contiguous subarray = {3 1 4} Max = 4
// 4th contiguous subarray = {1 4 5} Max = 5
// 5th contiguous subarray = {4 5 2} Max = 5
// 6th contiguous subarray = {5 2 3} Max = 5
// 7th contiguous subarray = {2 3 6} Max = 6
//brute force;
    //   for(int i=0;i<n-k+1;i++){
    //       int res=arr[i];
    //       for(int j=i;j<i+k;j++){
    //           res=max(res,arr[j]);
    //       }
    //       ans.push_back(res);
    //   }
    //   return ans ;
    // vector <int> max_of_subarrays(int *arr, int n, int k)
    // { 
    //   vector<int>ans;
    //   if(k>n){
    //       int res=*max_element(arr,arr+n);
    //       ans.push_back(res);
    //       return ans;
    //   }
    //   int i=0;
    //   int j=0;
    //   int res=INT_MIN;
    //   deque<int>q;
    //   while(j<n){
    //     while(!q.empty() && q.back()<arr[j] ){
    //         q.pop_back();
    //     }
    //     q.push_back(arr[j]);
    //       if(j-i+1<k){
    //           j++;
    //       }
    //       else{
    //           ans.push_back(q.front());
    //           if(arr[i]==q.front()){
    //               q.pop_front();
    //           }
    //           i++;
    //           j++;
    //       }
    //   }
    //   return ans;
    // }
