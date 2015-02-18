#include <iostream>
using namespace std;

int a[] = {4,20,7,8,2,9,3};

void max1_max2() {
	int max1 = a[0];
	int max2 = a[0];
	int max3 = a[0];
	int i;
	for(i = 0; i < 7; i++) {
		if(a[i] > max1) {
			max3 = max2;
			max2 = max1;
			max1 = a[i];
		} else {
			if(a[i] > max2) {
				max3 = max2;
				max2 = a[i];
			} else {
				if(a[i] > max3) {
					max3 = a[i];
				}
			}
		}
	}
	printf("%d %d %d\n", max1, max2, max3);
}

int main() {
	max1_max2();
	return 0;
}
