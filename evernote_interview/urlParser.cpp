#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void addKeyAndValueToMap(string s, unordered_map<string, string> &m) {
	string key, value;
	int equalSignIndex = s.find('=');
	key = s.substr(0, equalSignIndex);
	value = s.substr(equalSignIndex + 1);
	m[key] = value;
}

vector<string> split(string s, char delimiter) {
	vector<string> ret;
	stringstream ss(s);
	string item;
	while(getline(ss, item, delimiter)) {
		ret.push_back(item);
	}
	return ret;
}

unordered_map<string, string> getKeyAndValueInUrl(string url) {
	unordered_map<string, string> ret;
	int questionMarkIndex = url.find('?');
	if(questionMarkIndex == string::npos) {					//no key and value in url
		return ret;
	}
	string questionMarkToEnd = url.substr(questionMarkIndex + 1);
	vector<string> v = split(questionMarkToEnd, '&');
	for(int i = 0; i < v.size(); i++) {
		addKeyAndValueToMap(v[i], ret);
	}
	return ret;
}

void printMap(unordered_map<string, string> m) {
	unordered_map<string, string>::iterator it;
	for(it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}

int main() {
	string url = "https://www.google.com/search?q=dasfa&oq=dasfa&aqs=chrome..69i57j0l5.438j0j9&sourceid=chrome&es_sm=91&ie=UTF-8";
	unordered_map<string, string> m = getKeyAndValueInUrl(url);
	printMap(m);
	return 0;
}
