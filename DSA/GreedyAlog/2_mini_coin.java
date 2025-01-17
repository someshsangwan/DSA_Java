package GreedyAlog;

// given an array of coins u can use multiple times a coin , minimum no. of coins required to get amount;
//  [5,10,2,1] amount =57;
//  output=5+1+1=7   5 coins of 10 , 1 coin of 5 and 1 coin of 2;
import java.util.*;
class Solution{
    static List<Integer> minPartition(int N)
    {
        // code here
        int [] arr={1,2,5,10,20,50,100,200,500,2000};
        List<Integer>ans=new ArrayList<>();
        for(int i=9;i>=0;i--){
            int coin=N/arr[i];
            for(int j=0;j<coin;j++){
                ans.add(arr[i]);
                N=N-arr[i];
            }
            if(N==0){
                break;
            }
        }
        return ans;
        
    }
}