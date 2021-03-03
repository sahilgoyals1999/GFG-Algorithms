// https://practice.geeksforgeeks.org/problems/efficiently-sorting-number-from-0-to-n2-1/0
// T.C => O(n)

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

void countSort(int a[], int n, int exp) {
	int output[n], count[n] = {};
	for (int i = 0; i < n; ++i) {
		++count[(a[i] / exp) % n];
	}
	for (int i = 1; i < n; ++i) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; --i) {
		output[count[(a[i] / exp) % n] - 1] = a[i];
		--count[(a[i] / exp) % n];
	}
	for (int i = 0; i < n; i++) {
		a[i] = output[i];
	}
}

// Sort using Radix Sort
void sort(int a[], int n) {
	// Do counting sort for first digit in base n. Note that
	// instead of passing digit number, exp (n^0 = 1) is passed.
	countSort(a, n, 1);
	// Do counting sort for second digit in base n. Note that
	// instead of passing digit number, exp (n^1 = n) is passed.
	countSort(a, n, n);
}

int main() {
	FAST
	file();
	w(t) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, n);
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}