package DSA.BinarySearch;

public class Search {
    // Make the check method static to call it from the static main method
    public static boolean check(int[] arr, int x) {
        int n = arr.length; // Get the array length
        int start = 0; // Start index
        int end = n - 1; // End index
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid index
            if (arr[mid] == x) {
                return true; // 'x' found at mid index
            } else if (arr[mid] > x) {
                end = mid - 1; // 'x' is smaller, search in the left half
            } else {
                start = mid + 1; // 'x' is larger, search in the right half
            }
        }
        return false; // 'x' not found in the array
    }

    public static void main(String[] args) {
        // Array to search
        int arr[] = { 1, 4, 6, 34, 39, 41, 45 };

        // Check if 34 exists in the array, print the result
        System.out.println(check(arr, 34)); // Output should be true
    }
}
