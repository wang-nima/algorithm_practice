#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int index, vector<int> &v, vector<vector<int> > &result) {
    if(index == n) {
        result.push_back(v);
		return;
    }
	int i;
    for (i = 1; i <= n; i++) {
        v.push_back(i);
        dfs(n, index + 1, v, result);
        v.pop_back();
    }
}

void print(vector<vector<int> > v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
}

int main() {
    vector<int> v;
    vector<vector<int> > result;
    dfs(3, 0, v, result);
	print(result);
    return 0;
}
