// Single Source Shortest Path (Min Distance of all vertices from a single source)
// Similar to Prim's Algorithm
// T.C => O(E*log(V)) for using set and adjacency list
// T.C => O(V^2) for adjacency matrix

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

void dijkstras_shortest_path(int n, vector<vector<pii>> &g) {
	vector<bool> vis(n + 1, false);
	vector<int> dist(n + 1, INT_MAX);
	// set of pairs => for access of min dist edge
	set<pii> s;
	dist[1] = 0; // source node
	s.insert(mk(0, 1)); //push vertex 0(source vertex) with dist
	while (!s.empty()) {
		int tp = s.begin()->ss; //minVertex
		s.erase(s.begin()); // delete 1st element
		if (!vis[tp]) { //if is not visited already
			vis[tp] = true; //mark as visited
			for (auto child : g[tp]) { // visit all child vertices of tp
				// if child is not visited and its dist from source is less than existing dist at child
				// then upadte it and push it into the pq
				if (!vis[child.ss] &&  dist[tp] + child.ff < dist[child.ss] ) {
					if (dist[child.ss] != INT_MAX) { // it means node it already present in queue so remove it
						s.erase(s.find(mk(dist[child.ss], child.ss)));
					}
					dist[child.ss] = dist[tp] + child.ff;
					s.insert(mk(dist[child.ss], child.ss));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << i << " " << dist[i] << "\n";
	}
}

int main() {
	FIO
	file();
	w(t) {
		int n, m;
		cin >> n >> m;
		// pair ==> p.ff is dist and p.ss is edge
		// it is because of in set sorting is done on the basis of first element in the pair
		// 1-based indexing
		vector<vector<pii>> g(n + 1);
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].pb(mk(c, b));
			g[b].pb(mk(c, a));
		}
		dijkstras_shortest_path(n, g);
	}
	return 0;
}