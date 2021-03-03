// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#
// T.C => O(n+m) , S.C => O(n)

vector <int> bfs(vector<int> g[], int n) {
	vector<int> ans;
	queue<int> q;
	vector<bool> vis(n, false);
	q.push(0);
	vis[0] = true;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		ans.push_back(f);
		for (int child : g[f]) {
			if (!vis[child]) {
				vis[child] = true;
				q.push(child);
			}
		}
	}
	return ans;
}