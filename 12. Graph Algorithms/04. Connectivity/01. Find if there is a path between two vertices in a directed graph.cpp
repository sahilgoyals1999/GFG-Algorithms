// https://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
// T.C => O(n + m)

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

// BFS
int is_path(int s, int d, vector<vector<int>> g, int n) {
	if (s == d) return 1;
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while (!q.empty()) {
		int tp = q.front();
		q.pop();
		for (int child : g[tp]) {
			if (!vis[child]) {
				if (child == d) return 1;
				vis[child] = true;
				q.push(child);
			}
		}
	}
	return 0;
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
		cin >> s >> d;
		cout << is_path(s, d, g, n) << "\n";
	}
	return 0;
}