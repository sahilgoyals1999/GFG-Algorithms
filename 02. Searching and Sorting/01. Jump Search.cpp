// https://www.geeksforgeeks.org/jump-search/
// T.C => O(sqrt(n)) , S.C => O(1)

// suppose we have an array a[] of size n and block (to be jumped) size m.
// Then we search at the indexes 0, m, 2*m ,..., k*m and so on.
// Once we find the interval (a[k*m] < x < a[(k+1)*m])
// we perform a linear search from the index k*m to find the element x.

// total number of jumps => ( n/m + (m-1) )
// for minimise the value of jumps m = sert(m)

int jump_sort(int a[], int n, int k) {
	int step = sqrt(n);
	int prev = 0;
	while (a[min(step, n) - 1] < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) return -1;
	}
	while (a[prev] < x) {
		prev++;
		if (prev == min(step, n)) return -1;
	}
	if (a[prev] == x) return prev;
	return -1;
}