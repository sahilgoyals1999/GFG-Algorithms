// https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo/0
// T.C => O(V+E)

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

int tme = 0, ans = 0;
// leaf node can never be a articulation point
void dfs(int u, vector<vector<int>> g, vector<bool> &vis, vector<int> &disc, vector<int> &low, stack<int> &s) {
	disc[u] = low[u] = ++tme;
	s.push(u);
	vis[u] = true;
	for (int v : g[u]) {
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (disc[v] == -1)  {
			dfs(v, g, vis, disc, low, s);
			// Check if the subtree rooted with v has a connection to one of the ancestors of u
			low[u]  = min(low[u], low[v]);
		}
		// Update low value of u for parent function calls.
		else if (vis[v]) {
			low[u] = min(low[u], disc[v]);
		}
	}
	int w = 0;
	if (low[u] == disc[u]) {
		while (s.top() != u) {
			w = s.top();
			cout << w << " ";
			vis[w] = false;
			s.pop();
		}
		w = s.top();
		cout << w << ",";
		vis[w] = false;
		s.pop();
	}
}

void BCC(vector<vector<int>> g, int n) {
	ans = 0;
	tme = 0;
	vector<bool> vis(n, false);
	vector<int> disc(n, -1);
	vector<int> low(n);
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (disc[i] == -1) {
			dfs(i, g, vis, disc, low, s);
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
		}
		BCC(g, n);
	}
	return 0;
}