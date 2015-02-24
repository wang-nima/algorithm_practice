class Solution {
public:
    bool f(const string &s, int x, int y) {
        while(x < y) {
            if(s[x] != s[y]) {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    string lp(const string &s, int x, int y) {
        if( f(s, x, y) ) {
            return s.substr(x, y-x+1);
        }
        string s1;
        string s2;
        if(x+1 < y) {
            s1 = lp(s, x+1, y);
        }
        if(x < y-1) {
             s2 = lp(s, x, y-1);
        }
        return s1.size() > s2.size() ? s1 : s2;
    }
    string longestPalindrome(string s) {
        if(s == "") return "";
        if(s.size() == 1)   return s;
        return lp(s, 0, s.size()-1);
    }
};
