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

void dfs(int v, vector<bool> &vis, vector<vector<int>> g) {
	vis[v] = true;
	for (int child : g[v]) {
		if (child != -1 && !vis[child]) {
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

void add_edge(int u, int v, vector<vector<int>> &g) {
	g[u].pb(v);
	g[v].pb(u);
}

void remove_edge(int u, int v, vector<vector<int>> &g) {
	// Find v in adjacency list of u
	auto it = find(g[u].begin(), g[u].end(), v);
	if (it != g[u].end()) *it = -1;
	// Find u in adjacency list of v
	auto it1 = find(g[v].begin(), g[v].end(), u);
	if (it1 != g[v].end()) *it1 = -1;
}

int dfs_count(int v, vector<bool> &vis, vector<vector<int>> &g) {
	vis[v] = true;
	int count = 1;
	for (int child : g[v]) {
		if (child != -1 && !vis[child]) {
			count += dfs_count(child, vis, g);
		}
	}
	return count;
}

bool is_valid_next_edge(int u, int v, vector<vector<int> > &g, int n) {
	// The edge u-v is valid in one of the following two cases:
	// (1) If v is the only adjacent vertex of u
	int count = 0;
	for (int child : g[u]) {
		if (child != -1) ++count;
	}
	if (count == 1) return true;
	// (2) If there are multiple adjacents, then u-v is not a bridge
	// Do following steps to check if u-v is a bridge
	// 2.(a) count of vertices reachable from u
	vector<bool> vis(n, false);
	int count1 = dfs_count(u, vis, g);
	// 2.(b) Remove edge (u, v) and after removing the edge, count vertices reachable from u
	remove_edge(u, v, g);
	vector<bool> vis1(n, false);
	int count2 = dfs_count(u, vis1, g);
	// 2.(c) Add the edge back to the graph
	add_edge(u, v, g);
	// 2.(d) If count1 is greater, then edge (u, v) is a bridge
	// because if we remove a edge and no. of components increases it means it is bridge
	return (count1 > count2) ? false : true;
}

void eulerian(int u, vector<vector<int> > &g, int n) {
	for (int v : g[u]) {
		// If edge u-v is not removed and it's a a valid next edge
		if (v != -1 && is_valid_next_edge(u, v, g, n)) {
			cout << u << "-" << v << "  ";
			remove_edge(u, v, g);
			eulerian(v, g, n);
		}
	}
}

int main() {
	FIO
	file();
	w(t) {
		// 0-based indexing
		int n, m;
		cin >> n >> m;
		vector<vector<int> > g(n);
		for (int i = 1; i <= m; ++i) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		int odd = 0, src = 0;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() % 2 != 0) {
				++odd;
				src = i;
			}
		}
		bool res = isConnected(n, g);
		// odd == 0 => start with any node
		// odd == 2 => start one of them
		// otherwise eulerian path and circuit is not found
		if (res && (odd == 0 || odd == 2)) {
			eulerian(src, g, n);
		}
		else cout << "NONE\n";
	}
	return 0;
}