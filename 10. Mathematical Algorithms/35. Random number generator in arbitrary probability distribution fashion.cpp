// https://www.geeksforgeeks.org/random-number-generator-in-arbitrary-probability-distribution-fashion/
// T.C => O(n)

// Utility function to find ceiling of r in arr[l..h] like lower_bound
int findCeil(int a[], int r, int l, int h) {
	while (l < h) {
		int mid = l + (h - l) / 2;
		(r > a[mid]) ? (l = mid + 1) : (h = mid);
	}
	return (a[l] >= r) ? l : -1;
}

// The main function that returns a random number from a[]
// according to distribution array defined by freq[]. n is size of arrays.
int myRand(int a[], int freq[], int n) {
	// Create and fill prefix array
	int prefix[n];
	prefix[0] = freq[0];
	for (int i = 1; i < n; ++i) {
		prefix[i] = prefix[i - 1] + freq[i];
	}
	// prefix[n-1] is sum of all frequencies.
	// Generate a random number with value from 1 to this sum
	int r = (rand() % prefix[n - 1]) + 1;
	// Find index of ceiling of r in prefix array
	int indexc = findCeil(prefix, r, 0, n - 1);
	return arr[indexc];
}
