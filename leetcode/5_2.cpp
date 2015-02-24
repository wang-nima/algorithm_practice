class Solution {
public:
    string longestPalindrome(string s) {
        string ret, t;
        int i;
        int l,r;
        int n = s.size();
        for(i = 0; i < n; i++) {
            l = i;
            r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            l++;
            r--;
            t = s.substr(l, r-l+1);
            if(t.size() > ret.size()) {
                ret = t;
            }
        }
        for(i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) {
                l = i;
                r = i + 1;
                while(l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }
                l++;
                r--;
                t = s.substr(l, r-l+1);
                if(t.size() > ret.size()) {
                    ret = t;
                }
            }
        }
        return ret;
    }
};
