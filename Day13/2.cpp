#include <iostream>
#include <vector>
using namespace std;
int foundel(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high-low) / 2;   // This removes the issue of integer overflow if n is large. 

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        };
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 3, 4, 7, 9, 11, 14, 16, 19, 21, 23, 27, 31, 45};
    int target = 16;

    int result = foundel(arr, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}