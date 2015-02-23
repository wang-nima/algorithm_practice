//https://oj.leetcode.com/problems/longest-palindromic-substring/
//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int n = s.size();
        if(n == 1)   return s;
        bool table[1001][1001];
        memset(table, false, sizeof(table));
        int i;
        int start;
		int maxlen;
		for(i = 0; i < n; i++) {
		    start = i;
		    maxlen = 1;
			table[i][i] = true;
		}
		for(i = 0; i < n-1; i++) {
			if(s[i] == s[i+1]) {
			    start = i;
			    maxlen = 2;
				table[i][i+1] = true;
			}
		}
		int len;
		int j;

		for(len = 3; len <= n; len++) {
		    for(i = 0; i < n - len + 1; i++) {
		        j = i + len - 1;
		        if(s[i] == s[j] && table[i+1][j-1]) {
		            table[i][j] = true;
		            start = i;
		            maxlen = len;
		        }
		    }
		}
		return s.substr(start, maxlen);
    }
};
