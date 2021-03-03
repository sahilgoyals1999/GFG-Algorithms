// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
// T.C => O(E*log(V))

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
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

// sort edges in increasing order of their weight
bool comp(pair<int, pii> &a, pair<int, pii> &b) {
	return a.ss.ss < b.ss.ss;
}

// UNION FIND USING RANK AND PATH COMPRESSION
int find_parent(int v, vector<int> &parent) {
	if (v == parent[v]) return v;
	return parent[v] = find_parent(parent[v], parent);
}

int KruskalMST(int n, vector<pair<int, pii>> g) {
	// parent => for drawing tree
	// siz => for storing the size of each component
	vector<int> parent(n + 1), siz(n + 1);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		siz[i] = 1;
	}
	int count = n - 1, i = 0, ans = 0;
	// collect (n-1) edges
	while (count > 0) {
		// their is a edge b/w u and v
		int u = g[i].ff;
		int v = g[i].ss.ff;
		int up = find_parent(u, parent);
		int vp = find_parent(v, parent);
		// if parent of u & v are not same it means it not form cycle
		if (up != vp) {
			ans += g[i].ss.ss;
			if (siz[up] > siz[vp]) swap(up, vp);
			parent[up] = vp;
			siz[vp] += siz[up];
			--count;
		}
		++i;
	}
	return ans;
}

int main() {
	FIO
	file();
	w(t) {
		int n, m;
		cin >> n >> m;
		// storing edges
		// 1-beased indexing
		vector<pair<int, pii>> g(m);
		for (int i = 0; i < m; ++i) {
			cin >> g[i].ff >> g[i].ss.ff >> g[i].ss.ss;
		}
		sort(g.begin(), g.end(), comp);
		cout << KruskalMST(n, g) << "\n";
	}
	return 0;
}