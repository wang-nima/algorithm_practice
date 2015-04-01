#include <iostream>
#include <vector>
using namespace std;

class addValue {
private:
	int val;
public:
	addValue(int val) : val(val) {}
	void operator () (int x) {
		cout << x + val << endl;
	} 
};

int main() {
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for_each(v.begin(), v.end(), addValue(1));
	//for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
	//	cout << *it << " ";
	//}
	//cout << endl;
	return 0;
}
