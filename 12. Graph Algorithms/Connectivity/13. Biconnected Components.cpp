// https://www.geeksforgeeks.org/biconnected-components/
// T.C => O()
// John Hopcroft and Robert Tarjan Algorithm

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

int t = 0, ans = 0;
// leaf node can never be a articulation point
void dfs(int u, vector<vector<int>> g, vector<bool> &vis, vector<int> &parent,
         vector<int> &disc, vector<int> &low, stack<pair<int, int> > &s) {
	vis[u] = true;
	disc[u] = low[u] = ++t;
	int children = 0;
	for (int v : g[u]) {
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!vis[v])  {
			++children;
			parent[v] = u;
			s.push(mk(u, v));
			dfs(v, g, vis, parent, disc, low, s);
			// Check if the subtree rooted with v has a connection to one of the ancestors of u
			low[u]  = min(low[u], low[v]);
			// u is an articulation point in following cases
			// (1) u is root of DFS tree and has two or more chilren.
			// (2) If u is not root and low value of one of its child is more than discovery value of u.
			if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u])) {
				while (s.top().ff != u || s.top().ss != v) {
					cout << s.top().ff << "-" << s.top().ss << " ";
					s.pop();
				}
				cout << s.top().ff << "-" << s.top().ss;
				s.pop();
				cout << "\n";
				++ans;
			}
		}
		// Update low value of u for parent function calls.
		else if (v != parent[u]) {
			low[u] = min(low[u], disc[v]);
			if (disc[v] < disc[u]) s.push(mk(u, v));
		}
	}
}

void BCC(vector<vector<int>> g, int n) {
	ans = 0;
	vector<bool> vis(n, false);
	vector<int> parent(n, -1);
	vector<int> disc(n);
	vector<int> low(n);
	stack<pair<int, int> > s;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i, g, vis, parent, disc, low, s);
		}
		int c = 0;
		while (!s.empty()) {
			c = 1;
			cout << s.top().ff << "-" << s.top().ss << " ";
			s.pop();
		}
		if (c == 1) {
			++ans;
			cout << "\n";
		}
	}
	cout << "No. of BCC => " << ans;
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
		BCC(g, n);
	}
	return 0;
}