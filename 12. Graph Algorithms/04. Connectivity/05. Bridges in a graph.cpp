// https://www.geeksforgeeks.org/bridge-in-a-graph/
// T.C => O(n + m)
// Similar to APs

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

int t = 0;

void dfs(int u, vector<vector<int>> g, vector<bool> &vis, vector<int> &parent, vector<int> &disc, vector<int> &low) {
	vis[u] = true;
	disc[u] = low[u] = ++t;
	for (int v : g[u]) {
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!vis[v])  {
			parent[v] = u;
			dfs(v, g, vis , parent, disc, low);
			// Check if the subtree rooted with v has a connection to one of the ancestors of u
			low[u]  = min(low[u], low[v]);
			// If the lowest vertex reachable from subtree under v is below u in DFS tree
			// then u-v is a bridge
			if (low[v] > disc[u]) cout << u << " " << v << ", "; // print bridge
		}
		// Update low value of u for parent function calls.
		else if (v != parent[u]) low[u] = min(low[u], disc[v]);
	}
}

void bridge(vector<vector<int>> g, int n) {
	vector<bool> vis(n, false);
	vector<int> parent(n, -1);
	vector<int> disc(n);
	vector<int> low(n);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i, g, vis, parent, disc, low);
		}
	}
	cout << "\n";
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
		bridge(g, n);
	}
	return 0;
}