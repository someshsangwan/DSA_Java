#include <bits/stdc++.h>
using namespace std;

int maxxx(int arr[], int n) { // Pass the size of the array as a parameter
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);
        res = max(res, sum);
    }
    return res;
}

int main() {
    int arr[] = {1, -1, 4, 6, -9, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array in main
    int res = maxxx(arr, n); // Pass the array and its size to the function
    cout << res << endl;
    return 0;
}
