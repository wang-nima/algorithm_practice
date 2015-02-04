#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	int i = 0;
	int j;
	vector<int> v;
	vector<int> index_zero;
	long long product = 1;
	int n;
	cin >> n;
	while(cin >> t)
	{
		v.push_back(t);
		if(t == 0) index_zero.push_back(i);
		product *= t;
		i++;
	}
	if(product != 0)
	{
		for(i = 0; i < n; i++)
		{
			cout << product / v[i] << endl;
		}
	}
	else if(index_zero.size() >= 2)
	{
		for(i = 0; i < n; i++)
		{
			cout << 0 << endl;
		}
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			if(i == index_zero[0])
			{
				long long temp = 1;
				for(j = 0; j < i; j++)
				{
					temp *= v[j];
				}
				for(j = i+1; j < n; j++)
				{
					temp *= v[j];
				}
				cout << temp << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
