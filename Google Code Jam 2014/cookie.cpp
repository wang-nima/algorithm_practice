#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int i = 1;
	while (t--) {
		double c, f, x;
		cin >> c >> f >> x;
		if (x <= c) {
			printf("Case #%d: %.7lf\n", i, x / 2);
			i++;
			continue;
		}
		double temp;
		double addNew = x / 2;
		int currentFarm = 1;
		do {
			temp = addNew;
			addNew = 0;
			double speed = 2.0;
			for (int i = 0; i < currentFarm; ++i) {
				addNew += c / speed;
				speed += f;
			}
			addNew += x / speed;
			currentFarm++;
		} while(addNew < temp);
		printf("Case #%d: %.7lf\n", i, temp);
		i++;
	}
	return 0;
}
