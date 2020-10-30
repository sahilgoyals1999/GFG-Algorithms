// https://practice.geeksforgeeks.org/problems/subsequence-matching/0#
// T.C => O(n)

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

int main() {
	FIO
	file();
	w(t) {
		string s;
		cin >> s;
		int n = s.length(), i = 0;
		while (i < n) {
			if (i + 2 < n && s[i] == 'R' && s[i + 1] == 'Y' && s[i + 2] == 'Y') i += 3;
			else if (i + 1 < n && s[i] == 'R' && s[i + 1] == 'Y') i += 2;
			else if (s[i] == 'R') ++i;
			else break;
		}
		if (i == n) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}