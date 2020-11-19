// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
// T.C => O()

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long long)(1e9+7)
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
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class node {
public:
	int color = 1;
	set<int> edges;
};

int canPaint(vector<node>& nodes, int n, int m) {
	// Create a vis array of n nodes, initialized to false
	vector<bool> vis(n + 1, false);
	// maxColors used till now are 1 as all nodes are painted color 1
	int maxColors = 1;
	// Do a full BFS traversal from all unvis starting points
	for (int sv = 1; sv <= n; ++sv) {   // sv => source verted
		if (vis[sv]) continue;
		// If the starting point is unvis, mark it vis and push it in queue
		vis[sv] = true;
		queue<int> q;
		q.push(sv);
		// BFS Travel starts here
		while (!q.empty()) {
			int tp = q.front();
			q.pop();
			// Checking all adjacent nodes to "tp" edge in our queue
			for (int child : nodes[tp].edges) {
				// IMPORTANT: If the color of the adjacent node is same, increase it by 1
				if (nodes[tp].color == nodes[child].color) ++nodes[child].color;
				// If number of colors used shoots m, return 0
				maxColors = max(maxColors, max(nodes[tp].color, nodes[child].color));
				if (maxColors > m) return 0;
				// If the adjacent node is not vis, mark it vis and push it in queue
				if (!vis[child]) {
					vis[child] = true;
					q.push(child);
				}
			}
		}
	}
	return 1;
}

int main() {
	FIO
	file();
	w(t) {
		int n, m, e;
		cin >> n >> m >> e;
		// Create a vector of n+1 nodes of type "node"
		vector<node> nodes(n + 1);
		// Add edges to each node as per given input
		for (int i = 0; i < e; ++i) {
			int s, d;
			cin >> s >> d;
			nodes[s].edges.insert(d);
			nodes[d].edges.insert(s);
		}
		bool res = canPaint(nodes, n, m);
		if (res) {
			cout << "YES ";
			for (int i = 1; i <= n; ++i) {
				cout << nodes[i].color << " ";
			}
		}
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}