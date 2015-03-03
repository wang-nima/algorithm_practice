#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const unsigned int N = 10;

//Knuth Shuffle, prove by induction

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

// return a random number from [x , y)
int getRandomNum(int x, int y) {
	return (rand() % (y - x)) + x;
}

void randomShuffle(vector<int> &v) {
	srand(time(0));
	for(int i = 0; i < v.size(); i++) {
		swap(v[i], v[getRandomNum(i, v.size())]);
	}
}

int main() {
	vector<int> v;
	for(int i = 0; i < N; i++) {
		v.push_back(i);
		cout << v[i] << " ";
	}
	cout << endl;	
	randomShuffle(v);
	for(int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
