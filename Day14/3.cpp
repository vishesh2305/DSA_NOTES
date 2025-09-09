#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    int arr1size = arr1.size();
    int arr2size = arr2.size();
    vector<int> mergedarr;

    int i = 0, j = 0;

    while (i < arr1size && j < arr2size) {
        if (arr1[i] < arr2[j]) {
            mergedarr.push_back(arr1[i]);
            i++;
        } else if (arr2[j] < arr1[i]) {
            mergedarr.push_back(arr2[j]);
            j++;
        } else {
            mergedarr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < arr1size) {
        mergedarr.push_back(arr1[i]);
        i++;
    }

    while (j < arr2size) {
        mergedarr.push_back(arr2[j]);
        j++;
    }

    return mergedarr;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 8, 10};
    vector<int> arr2 = {2, 4, 6, 8, 10, 12, 14};

    vector<int> result = merge(arr1, arr2);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
