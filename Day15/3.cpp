#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int start, int end)
{
    vector<int> temp;
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (j <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++)
    {
        arr[start + k] = temp[k];
    }
}
void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}
int main()
{
    vector<int> arr = {10, 2, 5, 8, 7, 0, -1, 5};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
};