#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

void combine(int *a, int n1, int n2) {
	int i = 0;
	int j = n1;
	int k = 0;
	int *b = (int*) malloc( (n1 + n2) * sizeof(int) );

	while(i < n1 && j < n1 + n2) {
		if(a[i] < a[j]) {
			b[k] = a[i];
			i++;
		} else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	//combine the rest part to b
	if(i == n1) {
		memcpy(b + k, a + j, (n1 + n2 - j) * sizeof(int));
	} else {	//j == n2
		memcpy(b + k, a + i, (n1 - i) * sizeof(int));
	}
	memcpy(a, b, (n1+n2)*sizeof(int));
}

void mergeSort(int *a, int n) {
	if(n == 1)	return;
	mergeSort(a, n / 2);
	mergeSort(a + n / 2, n - n / 2);		//the size of second part can be odd and can be larger that the first part by 1
	combine(a, n / 2, n - n / 2);
}

void print(int *a, int n) {
	int i;
	for(i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main ()
{
	int a[] = {5,2,8,9,0,10,3,4,1};
	mergeSort(a,9);
	print(a,9);
	return 0;
}
