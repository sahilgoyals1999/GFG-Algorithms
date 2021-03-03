// https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
// T.C => O(n^2), S.C => O(n)

// north-south coodinates
// of each City Pair
class CityPairs {
	int north;
	int south;
};

// comparison function to sort the given set of CityPairs
bool comp(CityPairs &a, CityPairs &b) {
	if (a.south == b.south) return a.north < b.north;
	return a.south < b.south;
}

// function to find the maximum number of bridges that can be built
int maxBridges(CityPairs a[], int n) {
	sort(a, a + n, comp);
	int dp[n];
	// logic of LIS applied on the northern coordinates
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[i].north >= a[j].north && dp[i] < 1 + dp[j])
				dp[i] = 1 + dp[j];
		}
	}
	return *max_element(dp, dp + n);
}