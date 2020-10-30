// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
// T.C => O(30)

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

// for shortest distance b/w 1 to 30
int bfs(int src, vector<int> &move) {
	vector<bool> vis(31, false);
	queue<pair<int, int>> q;
	q.push(mk(1, 0));
	vis[1] = true;
	while (!q.empty()) {
		pair<int, int> tp = q.front();
		if (tp.ff == 30) return tp.ss; 	// Reach Destination
		q.pop();
		// cost of (i+1) to (i+6) is 1
		for (int j = tp.ff + 1; j <= min(30, tp.ff + 6); ++j) {
			if (!vis[j]) {
				vis[j] = true;
				pair<int, int> p;
				p.ss = (tp.ss + 1);
				if (move[j] == -1) p.ff = j; // it means head of snake or ladder is not their
				else p.ff = move[j];
				q.push(p);
			}
		}
	}
	return -1;
}

int main() {
	FIO
	file();
	w(t) {
		int n;
		cin >> n;
		vector<int> move(31, -1);
		for (int i = 1; i <= n; ++i) {
			int a, b;
			cin >> a >> b;
			move[a] = b;
		}
		cout << bfs(1, move) << "\n";
	}
	return 0;
}