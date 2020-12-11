// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
// T.C => O(n^2), S.C => O(n^2)

// dp[i][j] => Max lps form (i,j) subsequence
// Returns the length of the longest palindromic subsequence in s
int lps(string s) {
	int n = s.length();
	int dp[n][n];
	// Strings of length 1 are palindrome of lentgh 1
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}
	// the lower diagonal values of table are useless and not filled in the process.
	// The values are filled in a manner similar to Matrix Chain Multiplication DP solution
	// L is length of substring
	for (int L = 2; L <= n; ++L) {
		for (int i = 0; i < n - L + 1; ++i) {
			int j = i + L - 1;
			if (s[i] == s[j] && L == 2) {
				dp[i][j] = 2;
			}
			else if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			}
		}
	}
	return dp[0][n - 1];
}


// For finding String

string longestPalSubseq(string &X) {
	// Find reverse of str
	string Y = X;
	reverse(Y.begin(), X.end());
	// Apply LCS
	int m = X.length();
	int n = Y.length();
	int L[m + 1][n + 1];
	// L[i][j] => length of LCS of X[0..i-1] and Y[0..j-1]
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0) L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
			else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	// Following code is used to print LCS
	int index = L[m][n];
	// Create a string length index+1 and fill it with \0
	string lcs(index + 1, '\0');
	// Start from the right-most-bottom-most corner and one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0) {
		// If current character in X[] and Y are same, then current character is part of LCS
		if (X[i - 1] == Y[j - 1]) {
			// Put current character in result
			lcs[index - 1] = X[i - 1];
			i--;
			j--;
			// reduce values of i, j and index
			index--;
		}
		// If not same, then find the larger of two and go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1]) i--;
		else j--;
	}
	return lcs;
}
