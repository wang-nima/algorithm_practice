#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
	unordered_set<int> s1,s2;
	s1.insert(1);
	s1.insert(2);
	s2.insert(2);
	s2.insert(1);
	cout << (s1 == s2) << endl;
	unordered_map<int,int> m1,m2;
	m1[0] = 1;
	m1[1] = 2;
	m2[1] = 2;
	m2[0] = 1;
	cout << (m1 == m2) << endl;
    return 0;
}
