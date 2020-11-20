// https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
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

void getZarr(string str, int Z[]) {
	int n = str.length();
	int left = 0, right = 0;
	for (int i = 1; i < n; ++i) {
		if (i > right) {
			left = right = i;
			while (right < n && str[right - left] == str[right]) {
				++right;
			}
			Z[i] = right - left;
			--right;
		}
		else {
			// we are operating index box
			int k = i - left;
			// if value does not stretches till right bound then just copy it
			if (Z[k] < right - i + 1) Z[i] = Z[k];
			else {
				// otherwise try to see there are more matches
				left = i;
				while (right < n && str[right - left] == str[right]) {
					++right;
				}
				Z[i] = right - left;
				--right;
			}
		}
	}
}

void search(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();
	// Create concatenated string "P$T"
	string concat = pat + "$" + txt;
	int l = concat.length();
	int Z[l];
	Z[0] = 0;
	getZarr(concat, Z);
	for (int i = 0; i < l; ++i) {
		// if Z[i] (matched region) is equal to pat length we got the pat
		if (Z[i] == m) cout << i - m - 1 << "\n";
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