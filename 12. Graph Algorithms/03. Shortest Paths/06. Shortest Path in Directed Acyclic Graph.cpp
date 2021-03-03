// Topological Sort
// T.C => O(V + E) for topolical sort

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

void topological_sort(int v, vector<bool> &vis, stack<int> &s, vector<vector<pii>> g) {
	vis[v] = true;
	for (auto child : g[v]) {
		if (!vis[child.ss])  {
			topological_sort(child.ss, vis, s, g);
		}
	}
	s.push(v);
}

void shortestPath(int src, int n, vector<vector<pii>> g) {
	stack<int> s; // for topological sort
	vector<int> dist(n + 1, INT_MAX);
	vector<bool> vis(n + 1, false);
	dist[src] = 0;
	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			topological_sort(i, vis, s, g);
		}
	}

	while (!s.empty()) {
		// Get the next vertex from topological order
		int tp = s.top();
		s.pop();
		// Update distances of all adjacent vertices
		if (dist[tp] != INT_MAX) {
			for (auto child : g[tp])  {
				if (dist[child.ss] > dist[tp] + child.ff) {
					dist[child.ss] = dist[tp] + child.ff;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] == INT_MAX ? cout << "INF\n" : cout << dist[i] << "\n";
	}
}

int main() {
	FIO
	file();
	w(t) {
		int n, m, src;
		cin >> n >> m;
		// pair ==> p.ff is dist and p.ss is edge
		// it is because of in set sorting is done on the basis of first element in the pair
		// 1-based indexing
		// Graph is DAG (Directed Acyclic Graph)
		vector<vector<pii>> g(n + 1);
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].pb(mk(c, b));
		}
		cin >> src;
		shortestPath(src, n, g);
	}
	return 0;
}