// https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/
// T.C => O(n^2)

// A utility function to count inversions in given array 'arr[]'
int getInvCount(int a[]) {
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			// Value 0 is used for empty space
			if (a[j] && a[i] && a[i] > a[j]) ++inv_count;
		}
	}
	return inv_count;
}

// This function returns true if given 8 puzzle is solvable.
bool isSolvable(int puzzle[3][3]) {
	// Count inversions in given 8 puzzle
	int invCount = getInvCount((int *)puzzle);
	// return true if inversion count is even.
	return (invCount % 2 == 0);
}

int main() {
	int puzzle[3][3] =  {{1, 8, 2},
		{0, 4, 3},  // Value 0 is used for empty space
		{7, 6, 5}
	};
	isSolvable(puzzle) ? cout << "Solvable" : cout << "Not Solvable";
	return 0;
}