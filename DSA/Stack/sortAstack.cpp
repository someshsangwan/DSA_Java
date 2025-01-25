#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* we have given a stack and this is not sort , our task iss to return a sort stack;
*/


void sortkr(stack<int>&s,int num){
    if(s.empty() || (!s.empty() && s.top()<num)){
        s.push(num);
        return;
    }
    int x=s.top();
    s.pop();
    sortkr(s,num);
    s.push(x);
}
void sort_stack(stack<int>&s,int n){
    if(s.size()==0){
        return;
    }
    int num=s.top();
    s.pop();
    sort_stack(s,n);
    sortkr(s,num);
}



int main(){
    stack<int>s;
    s.push(1);
    s.push(22);
    s.push(3);
    s.push(41);
    s.push(500);
    s.push(61);
    s.push(7);
    s.push(81);

    int n=s.size();
    sort_stack(s,n);
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}