//http://stackoverflow.com/questions/1349734/why-on-earth-would-anyone-use-set-instead-of-unordered-set
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
//unordered_set is a hash set, O(1) to insert to find if the element is in the set

int main()
{
	cout << "set" << endl;
	set<int> s;
	s.insert(2);
	s.insert(1);
	s.insert(5);
	s.insert(3);
	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	cout << "unordered_set" << endl;
	unordered_set<int> us;
	us.insert(2);
	us.insert(1);
	us.insert(5);
	us.insert(3);
	unordered_set<int>::iterator i;
	for(i = us.begin(); i != us.end(); i++) {
		cout << *i << endl;
	}
    return 0;
}
