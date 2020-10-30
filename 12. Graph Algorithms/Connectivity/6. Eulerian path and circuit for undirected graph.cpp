// https://www.geeksforgeeks.org/eulerian-path-and-circuit/
// T.C => O(n+m)
// Here, we consider only edges

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

void dfs(int v, vector<bool> &vis, vector<vector<int>> g) {
	vis[v] = true;
	for (int child : g[v]) {
		if (!vis[child]) {
			dfs(child, vis, g);
		}
	}
}

bool isConnected(int n, vector<vector<int>> g) {
	// Find a vertex with non-zero degree
	int i;
	for (i = 0; i < n; ++i) {
		if (g[i].size() != 0) break;
	}
	// If there are no edges in the graph, return true
	if (i == n) return true;
	// Start DFS traversal from a vertex with non-zero degree
	vector<bool> vis(n, false);
	dfs(i, vis, g);
	// Check if all non-zero degree vertices are visited
	for (i = 0; i < n; ++i) {
		if (!vis[i] && g[i].size() > 0) return false;
	}
	return true;
}

int main() {
	FIO
	file();
	w(t) {
		// 0-based indexing
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		int odd = 0 ;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() % 2 != 0) ++odd;
		}
		vector<bool> vis(n, false);
		bool res = isConnected(n, g);
		if (res) {
			if (odd == 0) cout << "Eulerian Cycle\n";
			else if (odd == 2) cout << "Eulerian Path\n";
			else cout << "NONE\n";
		}
		else cout << "NONE\n";
	}
	return 0;
}