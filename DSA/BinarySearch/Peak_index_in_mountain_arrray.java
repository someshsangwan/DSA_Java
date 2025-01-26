package BinarySearch;

public class Peak_index_in_mountain_arrray {
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
