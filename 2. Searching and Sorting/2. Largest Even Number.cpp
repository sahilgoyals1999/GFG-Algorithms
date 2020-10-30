// https://practice.geeksforgeeks.org/problems/largest-even-number/0
// T.C => O(n)
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

int main() {
	FIO
	file();
	w(t) {
		string s;
		cin >> s;
		int n = s.length(), m = INT_MAX;
		int count[10] = {};
		for (int i = 0; i < n; ++i) {
			int idx = s[i] - 48;
			if (idx % 2 == 0) m = min(m, idx);
			count[idx]++;
		}
		int j = 0;
		if (m != INT_MAX) {
			count[m]--;
			s[n - 1] = m + 48;
		}
		for (int i = 9; i >= 0; --i) {
			while (count[i] > 0) {
				s[j] = i + 48;
				++j;
				--count[i];
			}
		}
		cout << s << "\n";
	}
	return 0;
}