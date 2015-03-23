#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	int i = 1;
	int a[4][4];
	while (t--) {
		int ans1;
		cin >> ans1;
		unordered_set<int> s;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> a[i][j];
				if (i == ans1 - 1) {
					s.insert(a[i][j]);
				}
			}
		}
		int ans2;
		cin >> ans2;
		vector<int> result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> a[i][j];
				if (i == ans2 - 1 && s.find(a[i][j]) != s.end()) {
					result.push_back(a[i][j]);
				}
			}
		}
		if (result.size() == 0) {
			printf("Case #%d: Volunteer cheated!\n", i);
		} else if (result.size() >= 2) {
			printf("Case #%d: Bad magician!\n", i);
		} else {
			printf("Case #%d: %d\n", i, result[0]);
		}
		i++;
	}
	return 0;
}
