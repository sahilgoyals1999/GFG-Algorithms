// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// T.C => O(E*log(V)) for using heap and adjacency list
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

int primsMST(int n, vector<vector<pii>> &g) {
	vector<bool> vis(n + 1, false);
	vector<int> weight(n + 1, INT_MAX);
	vector<int> parent(n + 1); // for Drawing MST
	// MIN PRIORITY QUEUE => for access of min weight edge
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	weight[1] = 0;
	parent[1] = 1;
	pq.push(mk(0, 1)); //push vertex 0(source vertex) with weight 0
	for (int i = 2; i <= n; ++i) {
		pq.push(mk(INT_MAX, i)); // other with weigth INT_MAX
	}
	while (!pq.empty()) {
		int tp = pq.top().ss; //minVertex
		pq.pop();
		if (!vis[tp]) { //if is not visited already
			vis[tp] = true; //mark as visited
			for (auto child : g[tp]) { // visit all child vertices of tp
				// if child is not visited and its weight is less than existing weight at child
				// then upadte it and push it into the pq
				if (!vis[child.ss] && child.ff < weight[child.ss] ) {
					weight[child.ss] = child.ff;
					parent[child.ss] = tp;
					pq.push(child);
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += weight[i];
	}
	return sum;
}

int main() {
	FIO
	file();
	w(t) {
		int n, m;
		cin >> n >> m;
		// pair ==> p.ff is weight and p.ss is edge
		// it is because of in priority queue sorting is done on the basis of first element in thr pair
		// 1-based indexing
		vector<vector<pii>> g(n + 1);
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].pb(mk(c, b));
			g[b].pb(mk(c, a));
		}
		cout << primsMST(n, g) << "\n";
	}
	return 0;
}