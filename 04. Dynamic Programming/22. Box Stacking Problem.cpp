// https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
// T.C => O(n^2), S.C => O(n)

class Box {
public:
	// h --> height, w --> width, d --> depth, for simplicity of solution, always keep w <= d
	int h, w, d;
};

bool comp(Box &a, Box &b) {
	return (a.d * a.w) > (b.d * b.w);
}

// Returns the height of the tallest stack that can be formed with give type of boxes
int maxStackHeight(Box a[], int n) {
	/* Create an array of all rotations of given boxes
	   {1, 2, 3} => {{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
	Box rot[3 * n];
	int index = 0;
	for (int i = 0; i < n; ++i) {
		// Copy the original box
		rot[index].h = a[i].h;
		rot[index].w = min(a[i].d, a[i].w);
		rot[index].d = max(a[i].d, a[i].w);
		index++;
		// First rotation of box
		rot[index].h = a[i].w;
		rot[index].w = min(a[i].h, a[i].d);
		rot[index].d = max(a[i].h, a[i].d);
		index++;
		// Second rotation of box
		rot[index].h = a[i].d;
		rot[index].w = min(a[i].h, a[i].w);
		rot[index].d = max(a[i].h, a[i].w);
		index++;
	}
	// Now the number of boxes is 3n
	n = 3 * n;
	// Sort the array 'rot[]' in non-increasing order of base area
	sort(rot, rot + n, comp);
	int dp[n];
	for (int i = 0; i < n; ++i) {
		dp[i] = rot[i].h;
		for (int j = 0; j < i; ++j) {
			if (rot[i].w < rot[j].w && rot[i].d < rot[j].d && dp[i] < dp[j] + rot[i].h) {
				dp[i] = dp[j] + rot[i].h;
			}
		}
	}
	return *max_element(dp, dp + n);
}