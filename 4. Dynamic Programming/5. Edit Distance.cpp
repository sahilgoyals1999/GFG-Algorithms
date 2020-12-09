// https://www.geeksforgeeks.org/edit-distance-dp-5/
// T.C => O(n*m), S.C => O(n*m)

// if last characters are same => Ignore last characters and recur for lengths n-1 and m-1.
// else, we consider all operations on ‘s’, recursively compute minimum cost for all three operetaions
// Insert(a): Recur for n and m-1
// Remove(b): Recur for n-1 and m
// Replace(c): Recur for n-1 and m-1
// ans = 1 + min({a ,b , c})

int editDistDP(string s, string t) {
	int n = s.length();
	int m = t.length();
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			// If first string is empty, only option is to insert all characters of second string
			if (i == 0) dp[i][j] = j; // Min. operations = j
			// If second string is empty, only option is to remove all characters of second string
			else if (j == 0) dp[i][j] = i; // Min. operations = i
			// If last characters are same, ignore last char and recur for remaining string
			else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			// If the last character is different, consider all possibilities and find the minimum
			else {
				dp[i][j] = 1 + min({dp[i][j - 1],      // Insert
				                    dp[i - 1][j],      // Remove
				                    dp[i - 1][j - 1]   // Replace
				                   });
			}
		}
	}
	return dp[n][m];
}