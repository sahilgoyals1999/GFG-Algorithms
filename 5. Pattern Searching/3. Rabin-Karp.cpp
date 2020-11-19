// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// T.C => for Avg. O(n + m), for Worsrt O(n*m)

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

#define d 256
void search(string txt, string pat, int q)  {
	int n = txt.length();
	int m = pat.length();
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;
	// The value of h would be "pow(d, m-1)%q"
	for (int i = 0; i < m - 1; ++i) {
		h = (h * d) % q;
	}
	// Calculate the hash value of pattern and first window of text
	for (int i = 0; i < m; ++i) {
		p = (p * d + pat[i]) % q;
		t = (t * d + txt[i]) % q;
	}
	// Slide the pattern over text one by one
	for (int i = 0; i <= n - m; ++i) {
		// Check the hash values of current window of text and pattern.
		// If the hash values match
		if (p == t) {
			int j = 0;
			// Check for characters one by one
			while (j < m) {
				if (txt[i + j] != pat[j]) break;
				++j;
			}
			// if p == t and pat[0...m-1] = txt[i, i+1, ...i+m-1]
			if (j == m) cout << i << "\n";
		}
		// Calculate hash value for next window of text: Remove leading digit, add trailing digit
		if (i < n - m) {
			t = (d * (t - txt[i] * h) + txt[i + m]) % q;
			// We might get negative value of t, converting it to positive
			if (t < 0) t += q;
		}
	}
}

int main() {
	FIO
	file();
	w(t) {
		string txt, pat;
		cin >> txt >> pat;
		int q = 101; // Prime Number
		search(txt, pat, q);
	}
	return 0;
}