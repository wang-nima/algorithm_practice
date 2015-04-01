#include <iostream>
#include <vector>
using namespace std;
int main() {
	//C++ 11 standard
	vector<int> v = {1, 2, 3, 4};
	for (auto &i : v) {
		i++;
	}
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	int a[] = {6, 7, 8, 9};
	for (auto i : a) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}
