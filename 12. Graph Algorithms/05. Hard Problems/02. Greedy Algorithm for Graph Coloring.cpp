// https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
// T.C => O(n^2 + m)

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

void coloring(int n, vector<vector<int> > g) {
	vector<int> color(n, -1);
	// Assign the first color to first vertex
	color[0] = 0;
	// A temporary array to store the available colors.
	// True value of available[cr] would mean that the color cr is
	// assigned to one of its adjacent vertices.
	vector<bool> available(n, false);
	// Assign colors to remaining V-1 vertices
	for (int i = 1; i < n; ++i) {
		// Process all adjacent vertices and flag their colors as unavailable
		for (auto child : g[i]) {
			if (color[child] != -1) {
				available[color[child]] = true;
			}
		}
		// Find the first available color
		int cr;
		for (cr = 0; cr < n; ++cr) {
			if (!available[cr]) break;
		}

		color[i] = cr; // Assign the found color
		// Reset the values back to false for the next iteration
		for (auto child : g[i]) {
			if (color[child] != -1) {
				available[color[child]] = false;
			}
		}
	}
	// print the result
	for (int i = 0; i < n; ++i) {
		cout << i << " " << color[i] << "\n";
	}
}


int main() {
	FIO
	file();
	// 0-based indexing
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
		coloring(n, g);
	}
	return 0;
}