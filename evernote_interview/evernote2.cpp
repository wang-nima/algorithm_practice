#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct sort_pred {
    bool operator() (const pair<string,int> &left, const pair<string,int> &right) {
		if(left.second != right.second)
        	return left.second > right.second;
		else
		{
			return left.first < right.first;
		}
    }
};

int main()
{
	int n,k;
	map<string,int> m;
	cin >> n;
	string t;
	while(n--)
	{
		cin >> t;
		m[t]++;
	}
	cin >> k;

	vector<pair<string, int> > v(m.begin(), m.end());
	sort(v.begin(), v.end(), sort_pred());
	
	for(int i = 0; i < k; i++)
	{
		cout << v[i].first << endl;
	}
	return 0;
}
