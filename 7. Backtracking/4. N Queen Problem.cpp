// https://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
// T.C => O()

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long)(1e9+7)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define N 4

void printSolution(int board[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

bool isSafe(int board[N][N], int row, int col) {
	// Check this row on left side
	for (int i = 0; i < col; i++) {
		if (board[row][i]) return false;
	}
	// Check upper diagonal on left side
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (board[i][j]) return false;
	}
	// Check lower diagonal on left side
	for (int i = row, j = col; j >= 0 && i < N; ++i, --j) {
		if (board[i][j]) return false;
	}
	return true;
}

bool solveNQUtil(int board[N][N], int col) {
	// base case: If all queens are placed then return true
	if (col >= N) return true;
	// Consider this column and try placing this queen in all rows one by one
	for (int i = 0; i < N; ++i) {
		// Check if the queen can be placed on board[i][col]
		if (isSafe(board, i, col)) {
			// Place this queen in board[i][col]
			board[i][col] = 1;
			// recur to place rest of the queens
			if (solveNQUtil(board, col + 1)) return true;
			// If placing queen in board[i][col] doesn't lead to a solution,
			// then remove queen from board[i][col]
			board[i][col] = 0; // Backtracking
		}
	}
	// If the queen cannot be placed in any row in this colum col then return false
	return false;
}

bool solveNQ() {
	int board[N][N] = {};
	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}
	printSolution(board);
	return true;
}

int main() {
	FIO
	file();
	solveNQ();
	return 0;
}