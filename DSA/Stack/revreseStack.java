package Stack;

import java.util.Stack;

public class revreseStack {
    void reverse_stack(Stack<Integer> s) {
        if (s.size() == 0) {
            return;
        }
        int num = s.peek();
        s.pop();
        reverse_stack(s);
        // insert_at_bottom(s,num); have done before

    }

}
