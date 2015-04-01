// partition algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::partition
#include <vector>       // std::vector
using namespace std;

bool IsOdd (int i) { return (i%2)==1; }

//template<typename T>
//T::iterator partition(T::iterator begin, T::iterator end, bool (*f)(int)) {
//	return begin;
//}
vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end, bool (*f)(int) ) {
	vector<int>::iterator ptr = begin;
	for (vector<int>::iterator it = begin; it != end; ++it) {
		if (f(*it)) {
			swap(*it, *ptr);
			ptr++;
		}
	} 
	return ptr;
}

int main () {
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  std::vector<int>::iterator bound;
  //bound = std::partition (myvector.begin(), myvector.end(), IsOdd);
  bound = partition (myvector.begin(), myvector.end(), IsOdd);
  

  // print out content:
  std::cout << "odd elements:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=bound; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "even elements:";
  for (std::vector<int>::iterator it=bound; it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
