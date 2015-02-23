//https://www.hackerrank.com/challenges/unbounded-knapsack/submissions/code/2817813
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[2005];
int a[2005];
int n;

int f(int x) {
    if(dp[x] != -1) {
        return dp[x];
    }
    int i;
	int t;
    int maximum = 0;
    for(i = 0; i < n; i++) {
        if(x - a[i] < 0) {
			break;
        }
		t = f(x - a[i]) + a[i];
        if(t > maximum) {
            maximum = t;
        }
    }
    maximum = max(maximum, f(x-1));
    dp[x] = maximum; 
    return maximum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, i, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
    	memset(dp, -1, sizeof(dp));
    	dp[0] = 0;
        for(i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        cout << f(k) << endl;
    }
    return 0;
}
