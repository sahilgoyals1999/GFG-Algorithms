// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// T.C => O(n+m) , S.C => O(n)

void dfs_helper(vector<int> g[], vector<bool> &vis, int s, vector<int> &ans) {
	vis[s] = true;
	ans.push_back(s);
	for (int child : g[s]) {
		if (!vis[child]) {
			dfs_helper(g, vis, child, ans);
		}
	}
}

vector <int> dfs(vector<int> g[], int n) {
	vector<int> ans;
	vector<bool> vis(n, false);
	dfs_helper(g, vis, 0, ans);
	return ans;
}