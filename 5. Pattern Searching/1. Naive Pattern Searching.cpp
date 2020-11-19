// https://practice.geeksforgeeks.org/problems/subsequence-matching/0#
// T.C => O(m*(n-m+1))

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)1e18
#define mod     (long)1e9+7
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

void search(string pat, string txt) {
	int n = txt.length();
	int m = pat.length();
	// A loop to slide pat[] one by one
	for (int i = 0; i <= n - m; ++i) {
		int j = 0;
		// For current index i, check for pattern match
		while (j < m) {
			if (txt[i + j] != pat[j])  break;
			++j;
		}
		if (j == m) cout << "Pattern found at index " << i << "\n";
	}
}

int main() {
	FIO
	file();
	w(t) {
		string txt, pat;
		cin >> txt >> pat;
		search(pat, txt);
	}
	return 0;
}