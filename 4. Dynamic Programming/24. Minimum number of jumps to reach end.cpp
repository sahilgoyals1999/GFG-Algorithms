// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

// T.C => O(n^2), S.C => O(n)

int minJumps(int a[], int n) {
	if (n == 0 || a[0] == 0) return INT_MAX;
	int dp[n];
	dp[0] = 0;
	// Find the minimum number of jumps to reach a[i] from a[0], and assign this value to dp[i]
	for (int i = 1; i < n; ++i) {
		dp[i] = INT_MAX;
		for (int j = 0; j < i; ++j) {
			if (i <= j + a[j] && dp[j] != INT_MAX) {
				dp[i] = min(dp[i], dp[j] + 1);
				break;
			}
		}
	}
	return dp[n - 1];
}


// T.C => O(n), S.C => O(1)

int minJumps(int a[], int n) {
	// The number of jumps needed to reach the starting index is 0
	if (n <= 1) return 0;
	// Return -1 if not possible to jump
	if (a[0] == 0) return -1;
	// stores all time the maximal reachable index in the array.
	int maxReach = a[0];
	// stores the number of steps we can still take
	int step = a[0];
	// stores the number of jumps necessary to reach that maximal reachable position. => ans
	int jump = 1;
	for (int i = 1; i < n; ++i) {
		// Check if we have reached the end of the array
		if (i == n - 1) return jump;
		// updating maxReach
		maxReach = max(maxReach, i + a[i]);
		// we use a step to get to the current index
		step--;
		// If no further steps left
		if (step == 0) {
			// we must have used a jump
			jump++;
			// Check if the current index or lesser index is the maximum reach point from the previous indexes
			if (i >= maxReach) return -1;
			// re-initialize the steps to the amount of steps to reach maxReach from position i.
			step = maxReach - i;
		}
	}
	return -1;
}