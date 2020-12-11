// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
// T.C => O(n*k^2), S.C => O(n*k)

// dp[i][j] => minimum number of trials needed for i eggs and j floors.
// eggDrop(n, k) = 1 + min{max(eggDrop(n – 1, x – 1), eggDrop(n, k – x)), where x is in {1, 2, …, k}}
// if egg breaks then check for (n-1) eggs check in (x-1) floors => lower part
// else (n) eggs and check in (k-x) floors => upper part

// Function to get minimum number of trials needed in worst case with n eggs and k floors
int eggDrop(int n, int k) {
	int dp[n + 1][k + 1];
	// We need 1 trial for 1 floor and 0 trials for 0 floors
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = 1;
		dp[i][0] = 0;
	}
	// We always need j trials for 1 egg and j floors.
	for (int j = 1; j <= k; ++j) {
		dp[1][j] = j;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= k; ++j) {
			dp[i][j] = INT_MAX;
			for (int x = 1; x <= j; ++x) {
				dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][x - 1], dp[i][j - x]));
			}
		}
	}
	return dp[n][k];
}