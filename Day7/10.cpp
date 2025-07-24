#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{

    int arr[] = {10, 20, 30, 40, 2, 5, 7, 9, 8, 7, 0, 9, 2, 5, 2, 2, 5, 5};

    vector<pair<int, int>> vec;
    int length = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> m;

    for (int i = 0; i < length; i++)
    {
        m[arr[i]]++;
    };

    for (auto p : m)
    {
        cout << "Value is " << p.first << " And is comes : " << p.second << " times " << endl;
    }

    return 0;
}
