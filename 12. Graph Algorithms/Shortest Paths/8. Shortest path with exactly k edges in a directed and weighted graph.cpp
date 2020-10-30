// https://www.geeksforgeeks.org/shortest-path-with-exactly-k-edges-in-a-directed-and-weighted-graph-set-2/?ref=rp
// T.C => O(n*m) using dynamic programming

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

// Let dp[X][J] be the shortest path from node S to node X using exactly J edges in total
int smPath(int s, int d, vector<pair<pii, int> > g, int n, int k) {
	// to store dp
	vector<int> dp(n, INT_MAX);
	dp[s] = 0;
	// Loop to solve DP
	for (int i = 0; i < k; ++i) {
		// Initialising next state
		vector<int> dp1(n, INT_MAX);
		// Recurrence relation
		for (auto pp : g) {
			if (dp[pp.ff.ff] != INT_MAX) {
				dp1[pp.ff.ss] = min(dp1[pp.ff.ss], dp[pp.ff.ff] + pp.ss);
			}
		}
		for (int i = 0; i < n; ++i) {
			dp[i] = dp1[i];
		}
	}
	// Returning final answer
	return (dp[d] == INT_MAX) ? -1 : dp[d];
}

int main() {
	FIO
	file();
	w(t) {
		// 0-based indexing
		int n, m, s, d, k;
		cin >> n >> m;
		vector<pair<pii, int> > g(m);
		for (int i = 0; i < m; ++i) {
			cin >> g[i].ff.ff >> g[i].ff.ss >> g[i].ss;
		}
		cin >> s >> d >> k;
		cout << smPath(s, d, g, n, k) << "\n";
	}
	return 0;
}

