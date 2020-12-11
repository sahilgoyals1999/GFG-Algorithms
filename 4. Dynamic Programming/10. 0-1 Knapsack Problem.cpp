// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// T.C => O(n*W), S.C => O(n*W)

// dp[i][w] => max value till ith item by including or excluding

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {
	int dp[n + 1][W + 1];
	for (int i = 0; i <= n; ++i) {
		for (int w = 0; w <= W; ++w) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
			}
			else if (wt[i - 1] <= w) {                      // include ith element
				dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
			}
			else {                                          // exclude ith element
				dp[i][w] = dp[i - 1][w];
			}
		}
	}
	return dp[n][W];
}