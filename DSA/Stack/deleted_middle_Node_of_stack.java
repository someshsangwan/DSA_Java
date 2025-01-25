package Stack;

import java.util.Stack;

class Solution {
    // Function to delete middle element of a stack.
    public void delete(Stack<Integer> s, int size, int count) {
        if (count == size / 2) {
            s.pop();
            return;
        }
        int data = s.peek();
        s.pop();
        delete(s, size, count + 1);
        s.push(data);
    }

    public void deleteMid(Stack<Integer> s) {
        // code here
        int size = s.size();
        int count = 0;
        delete(s, size, count);
    }
}