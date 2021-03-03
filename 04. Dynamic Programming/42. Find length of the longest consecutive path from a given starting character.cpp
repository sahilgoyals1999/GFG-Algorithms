// https://www.geeksforgeeks.org/find-length-of-the-longest-consecutive-path-in-a-character-matrix/
// T.C => O(8*n*m), S.C => O(n*m)
// DFS with memoization

// to recur for adjacent cells.
int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};

// dp[i][j] => length of longest consecutive path starting at a[i][j].
int R = 1000, C = 1000;
char mat[R][C];
int dp[R][C];

// check whether mat[i][j] is a valid cell or not.
bool isvalid(int i, int j) {
	if (i < 0 || j < 0 || i >= R || j >= C) return false;
	return true;
}

// Check whether current character is adjacent to previous character or not.
bool isadjacent(char prev, char curr) {
	return ((curr - prev) == 1);
}

// i, j are the indices of the current cell and prev is the character processed in the parent call
int getLenUtil(int i, int j, char prev) {
	if (!isvalid(i, j) || !isadjacent(prev, mat[i][j])) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int ans = 0;  // Initialize answer
	// recur for paths with different adjacent cells and store
	// the length of longest path.
	for (int k = 0; k < 8; ++k) {
		ans = max(ans, 1 + getLenUtil(mat, i + x[k], j + y[k], mat[i][j]));
	}
	// save the answer and return
	return dp[i][j] = ans;
}

// Returns length of the longest path with all characters consecutive to each other.
int getLen(char s) {
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			// check for each possible starting point
			if (mat[i][j] == s) {
				// recur for all eight adjacent cells
				for (int k = 0; k < 8; ++k) {
					ans = max(ans, 1 + getLenUtil(i + x[k], j + y[k], mat[i][j]));
				}
			}
		}
	}
	return ans;
}
