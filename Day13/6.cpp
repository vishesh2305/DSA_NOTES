#include <iostream>
#include <vector>
using namespace std;



int findOccurrence(vector<int>& arr, int target, bool findFirst) {
int low = 0, high = arr.size() - 1;
int result = -1;

while (low <= high) {
int mid = low + (high - low) / 2;

if (arr[mid] == target) {
result = mid;
if (findFirst)
high = mid - 1; // move left
else
low = mid + 1;
} else if (arr[mid] < target)
low = mid + 1;
else
high = mid - 1;



}

return result;


};




int main()
{
    vector<int> arr = {1,2,3,3,3,4,5};
    int target = 3;

    bool a = true;
    int result = findOccurrence(arr, target, a);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}