// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0#
// T.C => O(n^3)

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define INF     (int)(1e7)
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

// traverse for all nodes as intermediate node
// (i <--> k <--> j)
// if (i --> j) is shorter then (i --> k --> j) then update it

void floydWarshall(int n, vector<vector<int> > &g, vector<vector<int> > &dist) {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
	FIO
// 	file();
	w(t) {
		int n;
		cin >> n;
		// adjacency matrix , 0-based
		vector<vector<int> > g(n, vector<int>(n));
		vector<vector<int> > dist(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
				dist[i][j] = g[i][j];
			}
		}
		floydWarshall(n, g, dist);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				(dist[i][j] == 1e7) ? cout << "INF " : cout << dist[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}