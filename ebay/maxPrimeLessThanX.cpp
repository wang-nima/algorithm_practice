#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;


bool isPrime(int x) {
    if(x == 2) return true;
    int i;
    int squareRoot = sqrt(x*1.0);
    for (int i = 2; i < squareRoot; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int maxPrime(int x) {
    int ret;
    while (!isPrime(x)) {
        x--;
    }
    return x;
}

int main() {
    cout << maxPrime(79) << endl;
    return 0;
}

