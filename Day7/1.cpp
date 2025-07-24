#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,2,5,7,9,8,7,0,9,2,5,2,2,5,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    sort(arr, arr + length);

    int start = 0;
    int end = length - 1;

    while (start < end) {
        int sum = arr[start] + arr[end];

        if (sum == target) {
            cout << "Pair Found: " << arr[start] << " + " << arr[end] << " = " << target << endl;

            // Skip duplicates
            while (start < end && arr[start] == arr[start + 1]) start++;
            while (start < end && arr[end] == arr[end - 1]) end--;

            start++;
            end--;
        }
        else if (sum < target) {
            start++;
        }
        else {
            end--;
        }
    }

    return 0;
}