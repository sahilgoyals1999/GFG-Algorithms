// https://www.geeksforgeeks.org/fundamentals-of-algorithms/
// T.C => O(n+m)

// Just check for CYCLE in undrirected graph and
// Number of Connected Components(C.C) is 1

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
	vector<bool> vis(n, false);
	// call dfs for source node is 0
	bool cycle_found = dfs(0, -1, g, vis);
	if (cycle_found) return false;
	// check for visited nodes
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) return false;
	}
	return true;
}