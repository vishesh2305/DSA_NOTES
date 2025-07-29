#include <iostream>
#include <string>
using namespace std;
int main()
{

    string a = "masai";
    int count = 0;
    int n = a.length();

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            count += n -1;
        }
    }

    cout << "Answer is : "<<count;
}