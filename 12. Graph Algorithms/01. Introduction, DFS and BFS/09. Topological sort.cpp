// https://practice.geeksforgeeks.org/problems/topological-sort/1#
// T.C => O(n+m) DFS
// just push all src nodes after all of its childs is visited

void dfs(int src, vector<int> g[], vector<int> &ans, vector<bool> &vis) {
	vis[src] = true;
	for (int child : g[src]) {
		if (!vis[child]) dfs(child, g, ans, vis);
	}
	ans.push_back(src);
}

vector<int> topoSort(int n, vector<int> g[]) {
	vector<bool> vis(n, false);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i, g, ans, vis);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}