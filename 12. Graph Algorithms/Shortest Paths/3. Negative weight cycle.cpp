// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
// T.C => O(n*m)
// Bellman–Ford Algorithm

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

int negative_weight_cycle(int n, vector<pair<int, pii>> g) {
	vector<int> dist(n, INT_MAX);
	dist[0] = 0; // src node
	// Relax all edges (n - 1) times.
	// A simple shortest path from src to any other vertex can have at-most (n - 1) edges.
	for (int i = 1; i <= n - 1; ++i) {
		for (auto pp : g) {
			if (dist[pp.ff] != INT_MAX && dist[pp.ff] + pp.ss.ss < dist[pp.ss.ff]) {
				dist[pp.ss.ff] = dist[pp.ff] + pp.ss.ss;
			}
		}
	}
	// Check for negative-weight cycles.
	// The above step guarantees shortest distances if graph doesn't contain negative weight cycle.
	// If we get a shorter path, then there is a cycle.
	for (auto pp : g) {
		if (dist[pp.ff] != INT_MAX && dist[pp.ff] + pp.ss.ss < dist[pp.ss.ff]) {
			return 1;
		}
	}
	// else print dist array
	// for(int i=0;i<n;++i) {
	// 	(dist[i]==INT_MAX) ? cout<<"inf\n" : cout<<dist[i]<<"\n";
	// }
	return 0;
}

int main() {
	FIO
	file();
	w(t) {
		int n, m;
		cin >> n >> m;
		// pair of pair ==> p.ff is src, p.ss.ff is dest and p.ff.ss is weight
		// 0-based indexing
		vector<pair<int, pii>> g(m);
		for (int i = 0; i < m; ++i) {
			cin >> g[i].ff >> g[i].ss.ff >> g[i].ss.ss;
		}
		cout << negative_weight_cycle(n, g) << "\n";
	}
	return 0;
}