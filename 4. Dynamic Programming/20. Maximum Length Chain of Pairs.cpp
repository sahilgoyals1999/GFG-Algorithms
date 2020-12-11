// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
// T.C => O(n^2), S.C => O(n)

// Structure for a Pair
class Pair {
public:
	int a;
	int b;
};

// sort acc to first element
bool comp(Pair &a, Pair &b) {
	return a.a < b.a;
}

int maxChainLength(Pair a[], int n) {
	sort(a, a + n, comp);
	int dp[n];
	for (int i = 1; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[j].b < a[i].a && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp, dp + n);
}