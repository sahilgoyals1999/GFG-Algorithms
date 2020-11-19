// https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/
// T.C => O(n)

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

#define MAX 256

bool compare(int a[], int b[]) {
	for (int i = 0; i < MAX; ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void search(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();
	// countP[]:  Store count of all characters of pattern
	// countTW[]: Store count of current window of text
	int countP[MAX] = {}, countTW[MAX] = {};
	for (int i = 0; i < m; ++i) {
		++countP[pat[i]];
		++countTW[txt[i]];
	}
	// Traverse through remaining characters of pattern
	for (int i = m; i < n; ++i) {
		// Compare counts of current window of text with counts of pattern[]
		if (compare(countP, countTW)) {
			cout << (i - m) << "\n";
		}
		// Add current character to current window
		++countTW[txt[i]];
		// Remove the first character of previous window
		--countTW[txt[i - m]];
	}
	// Check for the last window in text
	if (compare(countP, countTW)) {
		cout << (n - m) << "\n";
	}
}

int main() {
	FIO
	file();
	w(t) {
		string txt, pat;
		cin >> txt >> pat;
		search(txt, pat);
	}
	return 0;
}