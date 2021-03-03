// https://www.geeksforgeeks.org/fleurys-algorithm-for-printing-eulerian-path/
// T.C => ((n+m)^2)

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define ninf    (long)(-(1e9+7))
#define mod     (long)(1e9+7)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define pii     pair<int,int>
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

void dfs(int s, int v, int n, vector<vector<int>> g, vector<vector<int>> &tc) {
	tc[s][v] = 1;
	// Find all the vertices reachable through v
	for (int i = 0; i < n; ++i) {
		if (g[v][i] == 1 && !tc[s][i]) {
			dfs(s, i, n, g, tc);
		}
	}
}

void solve(vector<vector<int>> g, vector<vector<int>> &tc, int n) {
	for (int i = 0; i < n; ++i) {
		dfs(i, i, n, g, tc);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << tc[i][j] << " ";
		}
	}
	cout << "\n";
}

int main() {
	FIO
	file();
	w(t) {
		// 0-based indexing
		int n;
		cin >> n;
		vector<vector<int>> g(n, vector<int>(n));
		vector<vector<int>> tc(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
			}
		}
		solve(g, tc, n);
	}
	return 0;
}