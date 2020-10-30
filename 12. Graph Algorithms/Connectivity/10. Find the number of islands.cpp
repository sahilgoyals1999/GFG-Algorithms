// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
// T.C => O(n*m)

void dfs(int i, int j, vector<int> g[], int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m) return; // Out of Range
	if (g[i][j] == 0 || g[i][j] == -1) return;
	g[i][j] = -1; // Mark as Visited
	dfs(i - 1, j - 1, g, n, m);
	dfs(i - 1, j, g, n, m);
	dfs(i - 1, j + 1, g, n, m);
	dfs(i, j - 1, g, n, m);
	dfs(i, j + 1, g, n, m);
	dfs(i + 1, j - 1, g, n, m);
	dfs(i + 1, j, g, n, m);
	dfs(i + 1, j + 1, g, n, m);
}

int findIslands(vector<int> g[], int n, int m) {
	if (n == 0) return 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 1) {
				dfs(i, j, g, n, m);
				++ans;
			}
		}
	}
	return ans;
}
