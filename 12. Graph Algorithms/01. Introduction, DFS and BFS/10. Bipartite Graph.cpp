// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// T.C => O(n*n)

bool bfs(int src, vector<int> &col, int g[][MAX], int n) {
	queue<int> q;
	q.push(src);
	col[src] = 1; // assign color to src is 1
	while (!q.empty()) {
		int tp = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			if (g[tp][i] == 0) continue; // no edge b/w tp & i
			if (!col[i]) {
				col[i] = 3 - col[tp]; // assign color to child is opp to col[tp]
				q.push(i);
			}
			else if (col[tp] == col[i]) return 0;
		}
	}
	return 1;
}

bool isBipartite(int g[][MAX], int n) {
	vector<int> col(n, 0);
	// 0 -> NO COLOR
	// 1 -> COLOR NO. 1
	// 2 -> COLOR NO. 2
	for (int i = 0; i < n; ++i) {
		if (!col[i]) {
			bool res = bfs(i, col, g, n);
			if (!res) return false;
		}
	}
	return true;
}