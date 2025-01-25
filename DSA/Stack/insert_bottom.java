package Stack;

import java.util.Stack;

class Solution {
    public void insertatbottom(Stack<Integer> s, int size, int count, int val) {
        if (count == size) {
            s.push(val);
            return;
        }
        int data = s.peek();
        s.pop();
        insertatbottom(s, size, count, val);
        s.push(data);
    }

    public void insert(Stack<Integer> s, int val) {
        // code here
        int size = s.size();
        int count = 0;
        insertatbottom(s, size, count, val);
    }
}