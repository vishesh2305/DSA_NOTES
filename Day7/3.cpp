#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,2,5,7,9,8,7,0,9,2,5,2,2,5,5};
    int length = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int,int>> vec;

    for(int i=0; i<length; i++){
        vec.push_back({arr[i], i});
    };

    sort(vec.begin(), vec.end());

    int target = 7;

    int start = 0;
    int end = length - 1;

    while (start < end) {
        int sum = vec[start].first + vec[end].first;

        if (sum == target) {
            
            cout << "Pair Found: " << vec[start].first << " + " << vec[end].first << " = " << target << endl;
            cout << "Indexes Found: " << vec[start].second<<" " << vec[end].second << endl;
            // Skip duplicates
            while (start < end && vec[start].first == vec[start + 1].first) start++;
            while (start < end && vec[end].first == vec[end - 1].first) end--;

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