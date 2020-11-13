// https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
// T.C => O(log(n))

// Function to get median of a sorted array
int median(int a[], int n) {
	if (n % 2 == 0) return (a[n / 2] + a[n / 2 - 1]) / 2;
	else return a[n / 2];
}

// for getting median of two sorted array of size n
int getMedian(int a1[], int a2[], int n) {
	// return -1  for invalid input
	if (n <= 0) return -1;
	if (n == 1) return (a1[0] + a2[0]) / 2;
	if (n == 2) return (max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2;
	int m1 = median(a1, n); /* get the median of the first array */
	int m2 = median(a2, n); /* get the median of the second array */
	// if m1 < m2 then median must exist in a1[m1....] and a2[....m2]
	if (m1 < m2) {
		if (n % 2 == 0) return getMedian(a1 + n / 2 - 1, a2, n - n / 2 + 1);
		return getMedian(a1 + n / 2, a2, n - n / 2);
	}
	// if m1 > m2 then median must exist in a1[....m1] and a2[m2...] */
	else if (m1 > m2) {
		if (n % 2 == 0) return getMedian(a2 + n / 2 - 1, a1, n - n / 2 + 1);
		return getMedian(a2 + n / 2, a1, n - n / 2);
	}
	// If medians are equal then return m1
	return m1;
}
