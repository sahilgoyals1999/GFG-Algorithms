// it is a NP Problem its Approximate Algorithm never finds a vertex cover
// whose size is more than twice the size of minimum possible vertex cover.
// T.C => O(n + m)

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long)(1e9+7)
#define ninf    (long long)(-1e18)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define pii     pair<int,int>
#define FAST    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

void vertex_cover(vector<vector<int> > g, int n) {
	vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i) {
		// An edge is only picked when both vis[i] and vis[child] are false
		if (!vis[i]) {
			// Go through all adjacents of i and pick the first not yet visited vertex
			for (int child : g[i]) {
				if (!vis[child]) {
					// Add the vertices (u, v) to the result set.
					// We make the vertex u and v visited so that
					// all edges from/to them would be ignored
					vis[child] = true;
					vis[i]  = true;
					break;
				}
			}
		}
	}
	// Print the vertex cover
	for (int i = 0; i < n; ++i) {
		if (vis[i]) {
			cout << i << " ";
		}
	}
}

int main() {
	FAST
	file();
	w(t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > g(n);
		for (int i = 1; i <= m; ++i) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		vertex_cover(g, n);
	}
	return 0;
}