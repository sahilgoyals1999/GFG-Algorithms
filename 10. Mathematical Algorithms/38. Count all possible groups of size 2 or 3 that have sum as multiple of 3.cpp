// https://www.geeksforgeeks.org/count-possible-groups-size-2-3-sum-multiple-3/
// T.C => O(n)

int findgroups(int a[], int n) {
	// Create an array C[3] to store counts of elements with remainder 0, 1 and 2.
	// c[i] would store count of elements with remainder i
	int c[3] = {};
	int res = 0; // To store the result
	// Count elements with remainder 0, 1 and 2
	for (i = 0; i < n; i++) {
		c[a[i] % 3]++;
	}
	// Case 3: Count groups of size 2
	// a: from 0 remainder elements
	res += ((c[0] * (c[0] - 1)) / 2);
	// b: with one element with 1 remainder and other with 2 remainder
	res += (c[1] * c[2]);
	// Case 4: Count groups of size 3
	// a: with all 0 remainder elements
	res += (c[0] * (c[0] - 1) * (c[0] - 2)) / 6;
	// b: with all 1 remainder elements
	res += (c[1] * (c[1] - 1) * (c[1] - 2)) / 6;
	// c: with all 2 remainder elements
	res += ((c[2] * (c[2] - 1) * (c[2] - 2)) / 6);
	// d: with different remainders
	res += (c[0] * c[1] * c[2]);
	// Return total count stored in res
	return res;
}