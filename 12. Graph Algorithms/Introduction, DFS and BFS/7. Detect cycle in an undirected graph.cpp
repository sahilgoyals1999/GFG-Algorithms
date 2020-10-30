// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// T.C => O(n+m)

bool dfs(int s, int p, vector<int> g[], vector<bool> &vis) {
	if (vis[s]) return 1; // if node is already visited it means cycle is found
	vis[s] = true;
	bool cycle_found = 0;
	for (int child : g[s]) {
		// Don't call Recursive call for the parent
		if (child != p) {
			cycle_found |= dfs(child, s, g, vis);
		}
	}
	return cycle_found;
}

bool isCyclic(vector<int> g[], int n) {
	bool cycle_found = false;
	vector<bool> vis(n, false);
	// traverse for all components of the graph
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) cycle_found |= dfs(i, -1, g, vis);
	}
	return cycle_found;
}