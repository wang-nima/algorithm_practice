#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


bool f(string s) {
	unordered_set<char> set;
	for (int i = 0; i < s.size(); i++) {
		if (set.find(s[i]) == set.end()) {
			set.insert(s[i]);
		} else {
			if (s[i] != s[i-1]) {
				return false;
			}
		}
	}
	return true;
}

void f(vector<int> &a, int index, int n, int &sum, vector<string> s) {
	if (index == n) {
		string temp;
		for (int i = 0; i < n; i++) {
			temp += s[a[i]];
		}
		if (f(temp)) {
			sum++;
		}
		return;
	}
	for (int i = index; i < n; i++) {
		swap(a[index], a[i]);
		f(a, index + 1, n, sum, s);
		swap(a[index], a[i]);
	}
}

int main () { 
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		int n;
		cin >> n;
		vector<string> v;
		for (int j = 0; j < n; j++) {
			string t;
			cin >> t;
			v.push_back(t);
		}
		vector<int> a = {0, 1, 2, 3, 4, 5 ,6, 7, 8, 9};
		int sum = 0;
		f(a, 0, n, sum, v);
		printf("%d\n", sum);
	}
	return 0;
}
