// https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/
// just check for Strongly Connected Component
// Kosaraju Algorithm using DFS

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

void dfs(int s, vector<bool> &vis, vector<vector<int>> g) {
	vis[s] = true;
	for (int child : g[s]) {
		if (!vis[child]) {
			dfs(child, vis, g);
		}
	}
}

vector<vector<int>> get_transpose(vector<vector<int>> g, int n) {
	vector<vector<int>> reverse_graph(n);
	for (int i = 0; i < n; ++i) {
		for (int child : g[i]) {
			reverse_graph[child].pb(i);
		}
	}
	return reverse_graph;
}

int is_sc(vector<vector<int>> g, int n) {
	vector<bool> vis(n, false);
	vector<bool> vis1(n, false);
	dfs(0, vis, g);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) return 0;
	}
	vector<vector<int>> reverse_graph = get_transpose(g, n);
	dfs(0, vis1, reverse_graph);
	for (int i = 0; i < n; ++i) {
		if (!vis1[i]) return 0;
	}
	return 1;
}

int main() {
	FIO
	file();
	w(t) {
		// 0-based indexing
		int n, m, s, d;
		cin >> n >> m;
		// p.ff.ff => src , p.ff.ss => dest , p.ss => weight
		vector<vector<int>> g(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
		}
		cout << is_sc(g, n) << "\n";
	}
	return 0;
}