#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* problem is simple you have an array of n size that is fille dwith 1 to n number, every number appears exactly one time except one(appear two times) find that 
repeat number and missing number*/
// Input:[3 1 2 5 3] 

// Output:[3, 4] 

// A = 3, B = 4
//approach 1- using map;
int main(){
    int n=5;
    int arr[]={3,1,2,5,3};
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;

    }
    int a; //repeated number
    int b; //missing number
    int i=1;
    for(auto it:mp){
        if(it.second==2){
            a=it.first;
        }
        if(it.first!=i){ //map sorted array me store hota h iska fayda uthaya ja rha h ;
            b=i;
        }
        i++;
        //cout<<it.first<<endl;
    }
    cout<<a<<" "<<b<<endl;
}