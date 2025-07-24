#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

int main(){
    map<int,string> m;
    m[1] = "delhi";
    m[2] = "Mumbai";
    m[3] = "Chennai";
    m[2] = "Hyderabad";
    for(auto p: m){
        cout << p.first<<" " <<p.second<< endl;
    }
return 0;
};