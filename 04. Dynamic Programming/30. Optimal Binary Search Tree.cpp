// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/
// T.C => O(n^3), S.C => O(n^2)

// cost[i][j] = Optimal cost of binary search tree that can be formed from keys[i] to keys[j]

// to get sum of array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)  {
	int s = 0;
	for (int k = i; k <= j; ++k) {
		s += freq[k];
	}
	return s;
}

// minimum cost of a Binary Search Tree
int optimalSearchTree(int keys[], int freq[], int n) {
	int cost[n][n];
	// For a single key, cost is equal to frequency of the key
	for (int i = 0; i < n; ++i) {
		cost[i][i] = freq[i];
	}
	// L is chain length.
	for (int L = 2; L <= n; ++L) {
		// i is row number in cost[][]
		for (int i = 0; i <= n - L + 1; ++i) {
			// Get column number j
			int j = i + L - 1;
			cost[i][j] = INT_MAX;
			// Try making all keys in interval keys[i..j] as root
			for (int r = i; r <= j; ++r) {
				// c = cost when keys[r] becomes root of this subtree
				int c = sum(freq, i, j) + ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0);
				if (c < cost[i][j]) {
					cost[i][j] = c;
				}
			}
		}
	}
	return cost[0][n - 1];
}