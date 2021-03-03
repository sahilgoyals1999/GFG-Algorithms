// https://practice.geeksforgeeks.org/problems/print-adjacency-list/0
// T.C => O(n^2) , S.C => O(n^2)

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
#define pii     pair<int,int>
#define vi      vector<int>
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

int32_t main() {
	FIO
	IO();
	w(t) {
		int n, m;
		cin >> n >> m;
		vector<vi> g(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		for (int i = 0; i < n; ++i) {
			cout << i;
			for (int child : g[i]) {
				cout << "-> " << child;
			}
			cout << "\n";
		}
	}
	return 0;
}