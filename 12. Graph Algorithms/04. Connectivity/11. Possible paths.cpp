// https://practice.geeksforgeeks.org/problems/possible-paths/0
// T.C => (n^3)
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

int count_walks(vector<vector<int> > g, int s, int d, int k, int n) {
	// Table to be filled up using DP.
	// The value count[i][j][e] will
	// store count of possible walks from
	// i to j with exactly k edges
	int count[n][n][k + 1];
	// Loop for number of edges from 0 to k
	for (int e = 0; e <= k; ++e) {
		for (int i = 0; i < n; ++i) {      // for source
			for (int j = 0; j < n; ++j) {  // for destination
				// initialize value
				count[i][j][e] = 0;
				// from base cases
				if (e == 0 && i == j) count[i][j][e] = 1;
				if (e == 1 && g[i][j]) count[i][j][e] = 1;
				// go to adjacent only when the number of edges > 1
				if (e > 1) {
					for (int a = 0; a < n; ++a) { // adjacent of source i
						if (g[i][a]) {
							count[i][j][e] += count[a][j][e - 1];
						}
					}
				}
			}
		}
	}
	return count[s][d][k];
}

int main() {
	FIO
	file();
	w(t) {
		int n, s, d, k, ans = 0;
		cin >> n;
		vector<vector<int> > g(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
			}
		}
		cin >> s >> d >> k;
		cout << count_walks(g, s, d, k, n) << "\n";
	}
	return 0;
}