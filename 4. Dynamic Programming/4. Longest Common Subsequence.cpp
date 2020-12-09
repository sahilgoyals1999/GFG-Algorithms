// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// T.C => O(n*m), S.C => O(m)

// In each iteration of outer loop we only, need values from all columns of previous row only.
// dp[i][j] => LCS of s[0..i-1] and t[0..j-1]
int lcs(string s, string t) {
	int n = s.length(), m = t.length();
	int dp[2][m + 1];
	// for current and previous row
	int bi;
	for (int i = 0; i <= n; ++i) {
		bi = i & 1;
		for (int j = 0; j <= m; ++j) {
			if (i == 0 || j == 0) dp[bi][j] = 0;
			else if (s[i - 1] == t[j - 1]) dp[bi][j] = dp[1 - bi][j - 1] + 1;
			else dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
		}
	}
	return dp[bi][m];
}