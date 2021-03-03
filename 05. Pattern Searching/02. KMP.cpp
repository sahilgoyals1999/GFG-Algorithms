// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// T.C => O(n + m)

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

// Fills lps[] for given patttern pat[0..m-1]
// longest prefix suffix (lps)
// at every index we will store what is length of longest suffix present till now
// viz also present as a prefix in the pattern.
// lps[i] => last index of the prefix matched with a suffix.
void compute_LPS_Array(string pat, int *lps) {
	int len = 0, m = pat.length();
	lps[0] = 0; // lps[0] is always 0
	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			++len;
			lps[i] = len;
			++i;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				++i;
			}
		}
	}
}

void KMPSearch(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();
	// create lps[] that will hold the longest prefix suffix values for pattern
	int lps[m];
	// Preprocess the pattern (calculate lps[] array)
	compute_LPS_Array(pat, lps);
	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < n) {
		if (pat[j] == txt[i]) {
			++j;
			++i;
		}
		if (j == m) {
			cout << i - j << " ";
			j = lps[j - 1];
		}
		// mismatch after j matches
		else if (i < n && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters, they will match anyway
			if (j != 0) j = lps[j - 1];
			else i = i + 1;
		}
	}
}

int main() {
	FIO
	file();
	w(t) {
		string txt, pat;
		cin >> txt >> pat;
		KMPSearch(txt, pat);
	}
	return 0;
}

