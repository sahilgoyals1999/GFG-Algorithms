// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// Kadane’s Algorithm
// T.C => O(n), S.C => O(1)

int maxSubArraySum(int a[], int n) {
	int ans = INT_MIN, sum = 0, start = 0, end = 0, s = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (ans < sum) {
			ans = sum;
			start = s;
			end = i;
		}
		if (sum < 0) {
			sum = 0;
			s = i + 1;
		}
	}
	cout << start << " " << end << "\n";
	return ans;
}