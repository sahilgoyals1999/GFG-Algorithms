// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
// T.C => O(8^(n^2))

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long)(1e9+7)
#define ninf    (long long)(-1e18)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define pii     pair<int,int>
#define FAST    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

#define N 8

int isSafe(int x, int y, int sol[N][N]) {
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N]) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cout << sol[x][y] << " ";
		}
		cout << "\n";
	}
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]) {
	if (movei == N * N) return 1;     // solution is found
	// Try all next moves from the current coordinate x, y
	for (int k = 0; k < 8; ++k) {
		int next_x = x + xMove[k];
		int next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1) return 1;
			else sol[next_x][next_y] = -1;       // Backtracking
		}
	}
	return 0;
}

int solveKT() {
	int sol[N][N];
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			sol[x][y] = -1;
		}
	}
	// xMove[] and yMove[] define next move of Knight
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	// Since the Knight is initially at the first block
	sol[0][0] = 0;
	// Start from 0,0 and explore all tours using solveKTUtil()
	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	printSolution(sol);
	return 1;
}


int main() {
	FAST
	file();
	solveKT(); // for N = 8
	return 0;
}