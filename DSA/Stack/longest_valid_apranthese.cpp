#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Given a string containing just the characters '(' and ')', 
// find the length of the longest valid (well-formed) parentheses substring.
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

//approach-1 generate all subsequence and check valid and return max 
// appraoch 2- using stack time o(n) space o(n)
// approach 3 o(n) time space o(1);

 int longestValidParentheses(string s) {
        int n=s.size();
        int res=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(st.size()!=0){
                    st.pop();
                }
                if(st.size()==0){
                    st.push(i);
                }
                else{
                    res=max(res,i-st.top());
                }
            }
        }
        return res;
        
    }
// approach 3 
 int longestValidParentheses(string s) {
        int n=s.size();
        int res=0;
        int open=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else close++;
            if(close==open){
                res=max(res,2*open);
            }
            else if(open<close){
                open=0;
                close=0;
            }
        }
        open =0;
        close=0;
        for(int i=n-1;i<=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(close==open){
                res=max(res,2*open);
            }
            else if(open>close){
                open=0;
                close=0;
            }
        }
        return res;
        
    }