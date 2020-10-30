// https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long)(1e9+7)
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

// T.C => log(n)
ll solve(ll x, ll y) {
	if (y == 0) return 1;
	if (x == 0) return 0;
	if (y == 1) return x % mod;
	ll temp = solve(x, y / 2);
	temp = (temp % mod * temp % mod) % mod;
	if (y % 2 == 0) return temp;
	return (x % mod * temp % mod) % mod;
}

int main() {
	FIO
	file();
	w(t) {
		ll n, m = 0, s;
		cin >> n;
		s = n;
		while (s > 0) {
			m = m * 10 + s % 10;
			s /= 10;
		}
		cout << solve(n, m) << "\n";
	}
	return 0;
}