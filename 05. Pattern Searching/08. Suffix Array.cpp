// https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
// T.C => O(n^2 * log(n))

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

int comp(pair<int, string> &a, pair<int, string> &b) {
	return a.ss < b.ss;
}

void build_suffix_array(string txt, vector<pair<int, string>> &suffixes) {
	int n = txt.length();
	for (int i = 0; i < n; ++i) {
		suffixes[i].ff = i;
		suffixes[i].ss = txt.substr(i);
	}
	sort(suffixes.begin(), suffixes.end(), comp);
}

void search(string pat, string txt, vector<pair<int, string>> &suffixes) {
	int n = txt.length();
	int m = pat.length();
	// Do simple binary search for the pat in txt using the built suffix array
	int l = 0, r = n - 1;
	while (l <= r) {
		// See if 'pat' is prefix of middle suffix in suffix array
		int mid = l + (r - l) / 2;
		int res = pat.compare(suffixes[mid].ss.substr(0, m));
		// If match found at the middle
		if (res == 0) {
			cout << suffixes[mid].ff;
			return;
		}
		// Move to left half if pattern is alphabtically less than the mid suffix
		if (res < 0) r = mid - 1;
		// Otherwise move to right half
		else l = mid + 1;
	}
	// We reach here if return statement in loop is not executed
	cout << "Not found";
}

int main() {
	FIO
	file();
	w(t) {
		string txt, pat;
		cin >> txt >> pat;
		vector<pair<int, string>> suffixes(txt.length());
		build_suffix_array(txt, suffixes);
		search(pat, txt, suffixes);
	}
	return 0;
}