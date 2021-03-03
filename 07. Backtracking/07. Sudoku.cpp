// https://www.geeksforgeeks.org/sudoku-backtracking-7/
// T.C => O(9^(n*n))

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long long)(1e9+7)
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

#define N 9

void printGrid(int grid[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}

bool UsedInRow(int grid[N][N], int row, int num) {
	for (int j = 0; j < N; ++j) {
		if (grid[row][j] == num) return true;
	}
	return false;
}

bool UsedInCol(int grid[N][N], int col, int num) {
	for (int i = 0; i < N; ++i) {
		if (grid[i][col] == num) return true;
	}
	return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (grid[i + boxStartRow][j + boxStartCol] == num) return true;
		}
	}
	return false;
}


bool isSafe(int grid[N][N], int row, int col, int num) {
	// Check if 'num' is not already placed in current row, current column and current 3x3 box
	return !UsedInRow(grid, row, num)
	       && !UsedInCol(grid, col, num)
	       && !UsedInBox(grid, row - row % 3, col - col % 3, num)
	       && grid[row][col] == 0;
}

bool FindUnassignedLocation(int grid[N][N], int& i, int& j) {
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (grid[i][j] == 0) return true;
		}
	}
	return false;
}

bool SolveSudoku(int grid[N][N]) {
	int row, col;
	// If there is no unassigned location, we are done => Base Caee
	if (!FindUnassignedLocation(grid, row, col)) return true;
	// Consider digits 1 to 9
	for (int num = 1; num <= 9; ++num) {
		if (isSafe(grid, row, col, num)) {
			grid[row][col] = num; // Return, if success
			if (SolveSudoku(grid)) return true;
			// Failure, unmake & try again => Backtracking
			grid[row][col] = 0;
		}
	}
	// This triggers backtracking
	return false;
}

int main() {
	FIO
	file();
	w(t) {
		// 0 means unassigned cells
		int grid[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> grid[i][j];
			}
		}
		bool res = SolveSudoku(grid);
		if (res) printGrid(grid);
		else cout << "No solution exists";
	}
	return 0;
}