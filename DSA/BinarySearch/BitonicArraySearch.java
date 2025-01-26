package BinarySearch;

//Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
//A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
// first find that point where its changing i mean that bitonic point and  than apply binary search 0 to bitonic point and another for descending array from bitonic+1 
// to n-1;
public class BitonicArraySearch {
    // Function to find the peak index
    public static int findPeakIndex(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start; // Peak index
    }

    // Binary search in an increasing array
    public static int binarySearchAscending(int[] arr, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; // Element not found
    }

    // Binary search in a decreasing array
    public static int binarySearchDescending(int[] arr, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; // Element not found
    }

    // Function to search for an element in a bitonic array
    public static int searchInBitonicArray(int[] arr, int target) {
        int peakIndex = findPeakIndex(arr);

        // Search in the increasing part
        int result = binarySearchAscending(arr, target, 0, peakIndex);
        if (result != -1) {
            return result;
        }

        // Search in the decreasing part
        return binarySearchDescending(arr, target, peakIndex + 1, arr.length - 1);
    }

    public static void main(String[] args) {
        int[] arr = { 1, 3, 8, 12, 4, 2 };
        int target = 4;

        int index = searchInBitonicArray(arr, target);
        System.out.println("Index of " + target + ": " + index); // Output: 4
    }
}
