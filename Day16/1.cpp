#include <iostream>
#include <vector>
using namespace std;
int paritition(vector<int> &vec, int start, int end)
{
    int pivotel = vec[start];
    int i = start + 1;
    for (int j = start + 1; j <= end; j++)
    {
        if (vec[j] > pivotel)
        {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[start], vec[i - 1]);
    return i - 1;
}
void quicksort(vector<int> &vec, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivotIndex = paritition(vec, start, end);
    quicksort(vec, start, pivotIndex - 1);
    quicksort(vec, pivotIndex + 1, end);
}
int main()
{

    vector<int> vec = {7, 8, 1, 3, 1, 5, 6, 4};
    int start = 0;
    int end = vec.size() - 1;

    quicksort(vec, start, end);

    for (auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}