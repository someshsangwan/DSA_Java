package Stack;

import java.util.Stack;

public class BalancedParentheses {
    public boolean isValid(String str) {
        char arr[] = str.toCharArray();
        Stack<Character> s = new Stack<>();
        for (char c : arr) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else {
                if (s.isEmpty()) {
                    return false;
                }
                char top = s.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        if (!s.isEmpty()) {
            return false;
        }
        return true;

    }
}
