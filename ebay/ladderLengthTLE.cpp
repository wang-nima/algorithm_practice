#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

unordered_set<string> visited;
int letterDiff(const string &s1, const string &s2) {
    if (s1 == s2)   return 0;
    int sum = 0;
    for (int i = 0; i < s1.size(); i++) {       //s1 and s2 have the same length
        if (s1[i] != s2[i]) {
            sum++;
        }
    }
    return sum;
}
int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (letterDiff(start, end) == 1) {      //base case
        return 2;
    }
    int min = 999999;
    bool found = false;
    int temp;
    visited.insert(start);
    for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
        if (visited.find(*it) == visited.end() && letterDiff(start, *it) == 1) {
            temp = ladderLength(*it, end, dict);
            if(temp == 0) {
                continue;
            }
            found = true;
            if (temp < min) {
                min = temp;
            }
        }
    }
    visited.erase(start);
    if (!found)  return 0;
    return min + 1;
}

int main() {
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	cout << ladderLength("hit","cog",dict) << endl;

    return 0;
}
