#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> findAllDuplicate(vector<int> v) {
    int i;
    unordered_map<int, int> occur;
    for (i = 0; i < v.size(); i++) {
        occur[v[i]]++;
    }
    //remove single element
    for (unordered_map<int, int>::iterator it = occur.begin(); it != occur.end(); ) {
        if (it->second == 1) {
            it = occur.erase(it);
        }
		else {
			it++;
		}
    }
    return occur;
}

void print(unordered_map<int, int> m) {
    for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int main() {
    int a[] = {2, 2, 3, 5, 5 ,6, 5, 7};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    unordered_map<int, int> m = findAllDuplicate(v);
    print(m);
    return 0;
}
