// https://www.geeksforgeeks.org/union-find/

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)1e18
#define mod     (long)1e9+7
#define int     long long
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// UNION FIND or DISJOINT SET UNION(DSU)
// with UNION BY RANK and PATH COMPRESSION
// Avg T.C => O(1) for each union operation

int find_parent(int v, vector<int> &parent) {
	if (v == parent[v]) return v;
	return parent[v] = find_parent(parent[v], parent);
}

int32_t main() {
	FIO
	IO();
	w(t) {
		int n, m;
		cin >> n >> m;
		// siz => for storing the size of each component
		vector<int> parent(n), siz(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			siz[i] = 1;
		}
		int ans = 0;
		vector<pair<int, int>> g(m);
		for (int i = 0; i < m; ++i) {
			cin >> g[i].ff >> g[i].ss;
		}
		for (int i = 0; i < m; ++i) {
			// their is a edge b/w u and v
			int u = g[i].ff;
			int v = g[i].ss;
			int up = find_parent(u, parent);
			int vp = find_parent(v, parent);
			if (up == vp) {
				ans = 1; // cycle is found if parnets are equal
				break;
			}
			else {
				if (siz[up] > siz[vp]) swap(up, vp);
				parent[up] = vp;
				siz[vp] += siz[up];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}