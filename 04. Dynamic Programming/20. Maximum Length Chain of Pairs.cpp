// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
// T.C => O(n^2), S.C => O(n)

// Structure for a Pair
class Pair {
public:
	int first;
	int second;
};

// sort acc to first element
bool comp(Pair &a, Pair &b) {
	return a.first < b.first;
}

int maxChainLength(Pair a[], int n) {
	sort(a, a + n, comp);
	int dp[n];
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[j].second < a[i].first && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp, dp + n);
}