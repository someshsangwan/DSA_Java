package BinarySearch;

//given sorted rotated array 
//pivot element is (7,9,1,2,3):- 1 is pivot element :-
public class Pivot_element {
    public static int findPeakIndex(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If the middle element is less than the next element, move right
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                // Otherwise, move left
                end = mid;
            }
        }

        // At the end of the loop, start == end, which is the peak index
        return start;
    }

}
