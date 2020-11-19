// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
// T.C =>  O(2^(n^2))

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

#define N 4

void printSolution(int sol[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sol[i][j] << " ";
		}
		cout << "\n";
	}
}

bool isSafe(int maze[N][N], int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}
	if (isSafe(maze, x, y) == true) {
		sol[x][y] = 1;
		if (solveMazeUtil(maze, x + 1, y, sol) == true) return true;
		if (solveMazeUtil(maze, x, y + 1, sol) == true) return true;
		sol[x][y] = 0; //Backtracking
		return false;
	}
	return false;
}

bool solveMaze(int maze[N][N]) {
	int sol[N][N] = {};
	if (!solveMazeUtil(maze, 0, 0, sol)) {
		cout << "solution not exist\n";
		return false;
	}
	printSolution(sol);
	return true;
}

int main() {
	FAST
	file();
	w(t) {
		int maze[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> maze[i][j];
			}
		}
	}
	return 0;
}