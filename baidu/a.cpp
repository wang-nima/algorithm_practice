//1、实现一个函数，对一个正整数n，算得到1需要的最少操作次数。操作规则为：如果n为偶数，将其除以2；如果n为奇数，可以加1或减1；一直处理下去。
//
//例子：
//func(7) = 4，可以证明最少需要4次运算
//n = 7
//n-1 6
//n/2 3
//n-1 2
//n/2 1
//要求：实现函数(实现尽可能高效) int func(unsign int n)；n为输入，返回最小的运算次数。给出思路(文字描述)，完成代码，并分析你算法的时间复杂度。

#include <iostream>
#include <queue>
using namespace std;


int func(int x) {
	queue<int> q;
	q.push(x);
	q.push(0);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		int generation = q.front();
		q.pop();
		if (temp == 1) {
			return generation;
		}
		if ((temp & 1) == 0) {			// 偶数
			q.push(temp / 2);
			q.push(generation + 1);
		} else {						// 奇数
			q.push(temp + 1);
			q.push(generation + 1);
			q.push(temp - 1);
			q.push(generation + 1);
		}
	}
}

int main() {
	cout << func(7) << endl;
	return 0;
}
