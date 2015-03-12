#include <iostream>
#include <cctype>
#include <string>
using namespace std;

//reverse the longest word in str start from index
//return the end index
//e.g. str = "abc3" index = 0
//return 3

void swap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}

int reverseWord(string &str, int index) {
    int i;
    for (i = index; i < str.size(); i++) {
        if (!isalpha(str[i])) {
            break;
        }
    }
    int endIndex = i;
    int swapTimes = (endIndex - index) / 2;
    for (i = 0; i < swapTimes; i++) {
        swap(str[index+i], str[endIndex-1-i]);
    }
    return endIndex;
}

void reverse(string &str) {
    int nextIndex;
    for (int i = 0; i < str.size();) {
        if (!isalpha(str[i])) {
            i++;
            continue;
        }
        nextIndex = reverseWord(str, i);
        i = nextIndex;
    }
}

int main() {
    string s = "I have  36 books, 40 pens2, and 1 notebook.";
    reverse(s);
    cout << s << endl;
    return 0;
}
