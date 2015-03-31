#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s = "abc";
	for (auto c : s) { 
		cout << "[" << c << "] ";
	}
	cout << endl;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (auto i : v) {
		i++;
	}
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}
