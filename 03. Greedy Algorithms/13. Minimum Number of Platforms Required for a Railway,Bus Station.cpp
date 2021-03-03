// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// T.C => O(n*log(n))

// Returns minimum number of platforms reqquired
int find_platform(int arr[], int dep[], int n) {
	// Sort arrival and departure arrays
	sort(arr, arr + n);
	sort(dep, dep + n);
	// plat_needed indicates number of platforms needed at a time
	int plat_needed = 1, ans = 1;
	int i = 1, j = 0;
	// Similar to merge in merge sort to process all events in sorted order
	while (i < n && j < n) {
		// If next event in sorted order is arrival, increment count of platforms needed
		if (arr[i] <= dep[j]) {
			++plat_needed;
			++i;
		}
		// Else decrement count of platforms needed
		else if (arr[i] > dep[j]) {
			--plat_needed;
			++j;
		}
		// Update result if needed
		ans = max(ans, plat_needed);
	}
	return ans;
}