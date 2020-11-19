// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// T.C => O(n * n!)

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long)(1e9+7)
#define ninf    (long long)(-1e18)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define pii     pair<int,int>
#define FAST    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

vector<string> ans;

void permutaions(string s, int l, int r) {
	// Base Case
	if (l == r) {
		ans.pb(s);
		return;
	}
	for (int i = l ; i <= r; ++i) {
		swap(s[l], s[i]);
		permutaions(s, l + 1 , r);
		swap(s[l], s[i]);          // Backtracking
	}
}

int main() {
	FAST
// 	file();
	w(t) {
		ans.clear();
		string s;
		cin >> s;
		int l = 0, r = s.length() - 1;
		permutaions(s, 0 , r);
		sort(ans.begin(), ans.end());
		for (string &x : ans) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}