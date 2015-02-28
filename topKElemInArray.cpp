#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

vector<int> topKElem(vector<int> a, int k) {
	int n = a.size();
	if(n <= k) {
		return a;
	}
	make_heap(a.begin(), a.begin() + k, cmp);
	vector<int> ret(a.begin(), a.begin() + k);
	for(int i = k; i < n; i++) {
		if(a[i] > ret.front()) {
			pop_heap(ret.begin(), ret.end(), cmp);
			ret.pop_back();
			ret.push_back(a[i]);
			push_heap(ret.begin(), ret.end(), cmp);
		}
	}
	return ret;
}

int main()
{
	int a[] = {0,9,1,2,7,4,8,2};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + n);
	int k = 3;
	vector<int> top = topKElem(v, k);
	for(int i = 0; i < k; i++) {
		cout << top[i] << endl;
	}
	cout << endl;
    return 0;
}
