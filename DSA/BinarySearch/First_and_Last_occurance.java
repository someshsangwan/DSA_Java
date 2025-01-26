package DSA.BinarySearch;

public class First_and_Last_occurance {
    public static int leftoccurance(int[] arr, int x) {
        int n = arr.length; // Get the array length
        int start = 0; // Start index
        int end = n - 1; // End index
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid index
            if (arr[mid] == x) {
                ans = mid;
                end = mid - 1;
            } else if (arr[mid] > x) {
                end = mid - 1; // 'x' is smaller, search in the left half
            } else {
                start = mid + 1; // 'x' is larger, search in the right half
            }
        }
        return ans; // 'x' not found in the array
    }

    public static int rightoccurance(int[] arr, int x) {
        int n = arr.length; // Get the array length
        int start = 0; // Start index
        int end = n - 1; // End index
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid index
            if (arr[mid] == x) {
                ans = mid;
                start = mid + 1;
            } else if (arr[mid] > x) {
                end = mid - 1; // 'x' is smaller, search in the left half
            } else {
                start = mid + 1; // 'x' is larger, search in the right half
            }
        }
        return ans; // 'x' not found in the array
    }
}
