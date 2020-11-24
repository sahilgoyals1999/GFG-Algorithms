// https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
// T.C => O(n)

void randomize(int a[], int n) {
	// Use a different seed value so that we don't get same result each time we run this program
	srand (time(NULL));
	// Start from the last element and swap one by one.
	for (int i = n - 1; i > 0; --i) {
		// Pick a random index from 0 to i
		int j = rand() % (i + 1);
		// Swap arr[i] with the element at random index
		swap(a[i], a[j]);
	}
}
