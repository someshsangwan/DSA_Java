 
// probelm is that
// Given N activities with their start and finish day given in array start[ ] and end[ ]. 
// Select the maximum number of activities that can be performed by a single person, 
// assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.
// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation: (1,2) , (3,4) ,(2,3) ,(5,6);  isme se konse interval overlap nhi ho rhe h dekho bhaiay
// A person can perform activities 1, 2
// and 4.

// greedy - sorting lgti h isme jyadater yad rakhna mere bache ;
// sort array according to finish time;

// probelm is that
// Given N activities with their start and finish day given in array start[ ] and end[ ]. 
// Select the maximum number of activities that can be performed by a single person, 
// assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.
// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation: (1,2) , (3,4) ,(2,3) ,(5,6);  isme se konse interval overlap nhi ho rhe h dekho bhaiay
// A person can perform activities 1, 2
// and 4.

// greedy - sorting lgti h isme jyadater yad rakhna mere bache ;
// sort array according to finish time;
import java.util.*;

public class ActivitySelection {

    // Custom comparator to sort activities by their finish time
    static class Activity {
        int start, end;

        Activity(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static int activitySelection(int[] start, int[] end, int n) {
        // Create a list of activities
        List<Activity> activities = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            activities.add(new Activity(start[i], end[i]));
        }

        // Sort activities based on their finish time
        activities.sort((a, b) -> a.end - b.end);

        // Select activities
        int res = 1; // At least one activity can always be selected
        int prevEnd = activities.get(0).end;

        for (int i = 1; i < n; i++) {
            if (activities.get(i).start >= prevEnd) {
                res++;
                prevEnd = activities.get(i).end;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int N = 4;
        int[] start = {1, 3, 2, 5};
        int[] end = {2, 4, 3, 6};

        System.out.println("Maximum number of activities: " + activitySelection(start, end, N));
    }
}
