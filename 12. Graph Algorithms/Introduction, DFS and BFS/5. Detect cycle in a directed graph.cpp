// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#
// T.C => O(n+m) , S.C => O(n)

bool dfs(int cur, vector<bool> &vis, vector<bool> &stack, vector<int> g[]) {
	if (!vis[cur]) {
		vis[cur] = true;
		stack[cur] = true;
		for (int child : g[cur]) {
			if (!vis[child] && dfs(child, vis, stack, g)) return true;
			else if (stack[child]) return true;
		}
	}
	stack[cur] = false; // Backtracking
	return false;
}

bool isCyclic(int n, vector<int> g[])
{
	vector<bool> vis(n, false);   // for whole graph
	vector<bool> stack(n, false); // for a recursive call
	for (int i = 0; i < n; ++i) {
		if (dfs(i, vis, stack, g)) return true;
	}
	return false;
}