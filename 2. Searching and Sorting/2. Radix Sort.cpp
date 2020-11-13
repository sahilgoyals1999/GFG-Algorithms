// https://www.geeksforgeeks.org/radix-sort/
// T.C => O((n+b)*logb(k)) ,  here b => base, k => maximum possible value
// So, T.C => O((n+b)*c) , c => length of digits of longest number

// for base 10
int getMax(int a[], int n) {
	int mx = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] > mx) mx = a[i];
	}
	return mx;
}
void countSort(int a[], int n, int exp) {
	int output[n], count[10] = {};
	// Store count of occurrences in count[]
	for (int i = 0; i < n; ++i) {
		++count[(a[i] / exp) % 10];
	}
	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (int i = 1; i < 10; ++i) {
		count[i] += count[i - 1];
	}
	// Build the output array
	for (int i = n - 1; i >= 0; --i) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		--count[(a[i] / exp) % 10];
	}
	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; ++i) {
		a[i] = output[i];
	}
}

void radixsort(int a[], int n) {
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);
	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(a, n, exp);
	}
}