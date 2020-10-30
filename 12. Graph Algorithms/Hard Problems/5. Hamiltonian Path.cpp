// https://practice.geeksforgeeks.org/problems/hamiltonian-path/0
//

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

int ham_path(vector<vector<int> > g, vector<int> &path, vector<bool> &vis, int k, int n) {
	path.pb(k);
	if (path.size() == n) return 1;
	vis[k] = true;
	for (int child : g[k]) {
		if (!vis[child]) {
			bool res = ham_path(g, path, vis, child, n);
			if (res) return 1;
		}
	}
	path.pp();
	vis[k] = false;
	return 0;
}

int main() {
	FIO
	file();
	// 1-based indexing
	w(t) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<vector<int> > g(n + 1);
		for (int i = 1; i <= m; ++i) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		vector<int> path;
		vector<bool> vis(n + 1, false);
		for (int i = 1; i <= n; ++i) {
			ans = ham_path(g, path, vis, i, n);
			if (ans) break;
		}
		cout << ans << "\n";
	}
	return 0;
}