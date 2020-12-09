// https://www.geeksforgeeks.org/min-cost-path-dp-6/
// T.C => O(n*m), S.C => O(1)

int n = 3;
int m = 3;
// dp[i][j] => min cost to reach (i,j) from (i-1,j), (i,j-1), (i-1,j-1)
int minCost(int cost[n][m]) {
	// for 1st column
	for (int i = 1 ; i < n ; ++i) {
		cost[i][0] += cost[i - 1][0];
	}
	// for 1st row
	for (int j = 1 ; j < m ; ++j) {
		cost[0][j] += cost[0][j - 1];
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1 ; j < m; ++j) {
			cost[i][j] += min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1]));
		}
	}
	// returning the value in last cell
	return cost[n - 1][m - 1];
}