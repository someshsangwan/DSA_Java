import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution{
static List<Integer> FirstNegativeInteger(int arr[], int k) {
    // Create a list to store the result
    List<Integer> ans = new ArrayList<>();
    int n = arr.length;
    int i = 0, j = 0;

    // Create a queue to store negative integers
    Queue<Integer> q = new LinkedList<>();

    // Iterate through the array
    while (j < n) {
        // Add the current element to the queue if it is negative
        if (arr[j] < 0) {
            q.add(arr[j]);
        }

        // Check if the current window size is less than k
        if (j - i + 1 < k) {
            j++;
        } else {
            // If the window size is exactly k, process the window
            if (q.isEmpty()) {
                ans.add(0); // No negative number in the current window
            } else {
                ans.add(q.peek()); // Add the first negative number
                // Remove the element going out of the window
                if (q.peek() == arr[i]) {
                    q.remove();
                }
            }

            // Slide the window
            i++;
            j++;
        }
    }

    return ans;
}
}
