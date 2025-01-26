package BinarySearch;

import java.util.Scanner;

public class SQRT {
    // Normal bruet force o(sqrt(n))
    // int floorSqrt(int n) {
    // int res = 1;
    // while(res*res <= n){
    // res++;
    // }
    // return res - 1;
    // }
    // using binary search o(logn)
    public static int findIntegerSquareRoot(int number) {
        int start = 0;
        int end = number;
        int result = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid * mid == number) {
                return mid; // Perfect square
            } else if (mid * mid < number) {
                result = mid; // Store the floor value
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return result; // Return the integer part of the square root
    }

    // Method to refine the square root to the desired precision
    public static double morePrecision(int n, int precision, int tempSol) {
        double factor = 1;
        double ans = tempSol;

        for (int i = 0; i < precision; i++) {
            factor = factor / 10;

            for (double j = ans; j * j < n; j = j + factor) {
                ans = j;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int n = scanner.nextInt();

        int tempSol = findIntegerSquareRoot(n);
        double sqrt = morePrecision(n, 3, tempSol);
        System.out.println("Square root of " + n + " is approximately: " + sqrt);
    }
}
