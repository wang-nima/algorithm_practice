#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

bool sulution(vector<int> v) {
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++) {
        m[v[i]]++;
    }
    int max = INT_MIN;
    for (unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }
    int sum = 0;
    for (unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second == max) {
            sum++;
        }
    }
    if (sum == 1) {
        return true;
    }
    return false;
}

int main() {
    int a1[] = {1, 2, 3};
    int a2[] = {1, 2, 3, 2};
    int a3[] = {1, 2, 3, 2, 3};
    int a4[] = {1, 2, 3, 4, 4, 4, 5, 5, 5};
	int a5[] = {1};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(int));
    vector<int> v2(a2, a2 + sizeof(a2) / sizeof(int));
    vector<int> v3(a3, a3 + sizeof(a3) / sizeof(int));
    vector<int> v4(a4, a4 + sizeof(a4) / sizeof(int));
    vector<int> v5(a5, a5 + sizeof(a5) / sizeof(int));

    cout << sulution(v1) << endl;
    cout << sulution(v2) << endl;
    cout << sulution(v3) << endl;
    cout << sulution(v4) << endl;   
    cout << sulution(v5) << endl;   
    return 0;
}
