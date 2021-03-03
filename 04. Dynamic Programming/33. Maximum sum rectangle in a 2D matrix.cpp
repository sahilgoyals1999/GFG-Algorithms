// https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
// T.C => O(n^3), S.C => O()

#define ROW 4
#define COL 5

// Implementation of Kadane's algorithm for D array.
// The function returns the maximum sum and stores starting and ending indexes
// of the maximum sum subarray at addresses pointed by start and finish pointers respectively.
int kadane(int* a, int &start, int &finish, int n) {
	int sum = 0, maxSum = INT_MIN;
	finish = -1;
	int local_start = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum) {
			maxSum = sum;
			start = local_start;
			finish = i;
		}
	}
	if (finish != -1) return maxSum;
	maxSum = a[0];
	start = finish = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] > maxSum) {
			maxSum = a[i];
			start = finish = i;
		}
	}
	return maxSum;
}

// The main function that finds maximum sum rectangle in M[][]
void findMaxSum(int M[][COL]) {
	// Variables to store the final output
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
	int start, finish;
	// Set the left column
	for (int left = 0; left < COL; ++left) {
		int temp[ROW] = {};
		// Set the right column
		for (int right = left; right < COL; ++right) {
			// Calculate sum between current left and right for every row 'i'
			for (int i = 0; i < ROW; ++i) {
				temp[i] += M[i][right];
			}
			// Find the maximum sum subarray in temp[].
			// The kadane() function also sets values of start and finish.
			// So 'sum' is sum of rectangle between (start, left) and
			// (finish, right) which is the maximum sum
			// with boundary columns strictly as left and right.
			int sum = kadane(temp, &start, &finish, ROW);
			// Compare sum with maximum sum so far.
			// If sum is more, then update maxSum and other output values
			if (sum > maxSum) {
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}
	// Print final values
	cout << "(Top, Left) (" << finalTop << ", " << finalLeft << ")\n";
	cout << "(Bottom, Right) (" << finalBottom << ", " << finalRight << ")\n";
	cout << "Max sum is: " << maxSum << "\n";
}