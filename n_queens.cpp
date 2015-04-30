#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cfloat>
using namespace std;

//const int mod = 1e+9 + 7;

typedef long long ll;

// before calling isSafe board[row][col] must be empty!
// because we insert queens row by row, so we only need to exam column and digonal
// we only need to example the above board
bool isSafe(const vector<string> board, int row, int col) {
	int n = board.size();
	// exam column
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][col] == 'Q') {
			return false;
		}
	}
	// exam digonal
	// lower left to upper right
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}
	// exam digonal
	// upper left to lower right
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}
	return true;
}

// currentRow is in [0, n-1]
void solve(int n, vector<string> currentBoard, vector<vector<string> > &result, int currentRow) {
	if (currentRow == n) {
		result.push_back(currentBoard);
	}
	for (int i = 0; i < n; i++) {
		if (isSafe(currentBoard, currentRow, i)) {
			currentBoard[currentRow][i] = 'Q';
			solve(n, currentBoard, result, currentRow + 1);
			currentBoard[currentRow][i] = '.';
		}
	}
}

void printBoard(vector<vector<string> > result, int n) {
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << endl;
		}
		cout << endl;
	}
}

vector<string> generateEmptyBoard(int n) {
	string s(n, '.');
	vector<string> ret(n, s);
	return ret;
}

vector<vector<string> > solveNQueens(int n) {
 	vector<vector<string> > ret;
	solve(n, generateEmptyBoard(n), ret, 0);
	printBoard(ret, n);
	return ret;
}

int main () { 
	solveNQueens(8);
	return 0;
}
