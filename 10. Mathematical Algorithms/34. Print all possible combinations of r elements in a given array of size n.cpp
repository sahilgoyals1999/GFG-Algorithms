// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
// T.C => O(n^2)

void combinationUtil(int a[], int data[], int start, int end, int index, int r) {
	// Current combination is ready to be printed, print it
	if (index == r) {
		for (int i = 0; i < r; ++i) {
			cout << data[i] << " ";
		}
		cout << "\n";
		return;
	}
	// replace index with all possible elements. The condition
	// "end-i+1 >= r-index" makes sure that including one element
	// at index will make a combination with remaining elements
	// at remaining positions
	for (int i = start; i <= end && end - i + 1 >= r - index; ++i) {
		data[index] = a[i];
		combinationUtil(a, data, i + 1, end, index + 1, r);
		// Remove duplicates
		while (a[i] == a[i + 1]) {
			++i;
		}
	}
}

// The main function that prints all combinations of size r in a[] of size n.
void printCombination(int a[], int n, int r) {
	// A temporary array to store all combination one by one
	int data[r];
	// Sort array to handle duplicates
	sort(a, a + n);
	// Print all combination using temprary array 'data[]'
	combinationUtil(a, data, 0, n - 1, 0, r);
}