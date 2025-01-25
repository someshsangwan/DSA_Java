package Stack;

import java.util.Stack;

class Solution {
    public void immediateSmaller(int arr[]) {
        int n = arr.length;
        Stack<Integer> s = new Stack<>();
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int x = arr[i];
            while (s.peek() >= x) {
                s.pop();
            }
            int top = s.peek();
            s.push(arr[i]);
            arr[i] = top;

        }
    }
}
// prev smaller -- int i=0;i<n;i++ while(s.top()>=curr);
// prev greater -- int i=0;i<n;i++ while(s.top()<=curr);