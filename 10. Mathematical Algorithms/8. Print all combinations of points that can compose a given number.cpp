// https://www.geeksforgeeks.org/print-all-combinations-of-points-that-can-compose-a-given-number/
//

#define MAX_POINT 3
#define ARR_SIZE 100

void printArray(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void printCompositions(int n, int size = 0) {
	/* array must be static as we want to keep track
	of values stored in arr[] using current calls of
	printCompositions() in function call stack*/
	static int a[ARR_SIZE];
	if (n == 0) {
		printArray(a, size);
	}
	else if (n > 0) {
		int k;
		for (int k = 1; k <= MAX_POINT; ++k) {
			a[i] = k;
			printCompositions(n - k, size + 1);
		}
	}
}