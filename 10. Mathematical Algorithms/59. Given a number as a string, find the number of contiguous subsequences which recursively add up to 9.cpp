// https://www.geeksforgeeks.org/given-number-find-number-contiguous-subsequences-recursively-add-9/
// T.C => O(n)

int count9s(string num) {
	int n = num.length();
	int dp[10] = {};
	dp[0] = 1;
	int ans = 0, sum = 0;
	int cnt_zero = 0;
	for (int i = 0; i < n; ++i) {
		if ((num[i] - '0') == 0) ++cnt_zero;
		else cnt_zero = 0;
		sum = (sum + num[i] - '0') % 9;
		ans += dp[sum];
		dp[sum]++;
		ans -= cnt_zero;
	}
	return ans;
}
