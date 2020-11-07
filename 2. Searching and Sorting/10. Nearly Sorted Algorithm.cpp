// https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
// T.C => O(k) + O((n-k)*log(K))

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

int main() {
	FAST
	file();
	w(t) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		// Insert first k+1 items in a priority queue (or min heap)
		priority_queue<int, vector<int>, greater<int> > pq(a, a + k + 1);

		int index = 0;
		for (int i = k + 1; i < n; ++i) {
			a[index++] = pq.top();
			pq.pop();
			pq.push(a[i]);
		}
		while (!pq.empty()) {
			a[index++] = pq.top();
			pq.pop();
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}