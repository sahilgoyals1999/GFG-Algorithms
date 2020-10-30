// https://www.geeksforgeeks.org/strongly-connected-components/
// Kosaraju’s algorithm
// T.C =>  O(n+m)

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
	cout << v << " ";
	for (int child : g[v]) {
		if (!vis[child]) {
			dfs(child, vis, g);
		}
	}
}

void fill_order(int v, vector<bool> &vis, vector<vector<int>> g, stack<int> &s) {
	vis[v] = true;
	for (int child : g[v]) {
		if (!vis[child]) {
			fill_order(child, vis, g, s);
		}
	}
	s.push(v);
}

vector<vector<int>> get_transpose(vector<vector<int>> g, int n) {
	vector<vector<int>> gr(n);
	for (int i = 0; i < n; ++i) {
		for (int child : g[i]) {
			gr[child].pb(i);
		}
	}
	return gr;
}

void kosaraju(vector<vector<int> > g, int n) {
	stack<int> s;
	vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			fill_order(i, vis, g, s);
		}
	}
	// Create a reversed graph
	vector<vector<int> >  gr = get_transpose(g, n);
	vector<bool> vis1(n, false) ;
	while (!s.empty()) {
		// Pop a vertex from stack
		int tp = s.top();
		s.pop();
		if (!vis1[tp]) {
			dfs(tp, vis1, gr);
			cout << "\n";
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
		}
		kosaraju(g, n);
	}
	return 0;
}