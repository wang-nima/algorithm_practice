#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int sum = 0;
	vector<int> v = {1, 2, 3, 4, 5};
	//sum is a parameter of lamda
	for_each(v.begin(), v.end(),[&sum](int x){ sum += x; });
	cout << sum << endl;

	//increase everthing in vector by 1
	for_each(v.begin(), v.end(),[](int &x){ x++; });

	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
