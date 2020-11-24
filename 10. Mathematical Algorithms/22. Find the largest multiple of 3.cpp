// https://www.geeksforgeeks.org/find-the-largest-number-multiple-of-3/
// T.C => O(n)

#define MAX_SIZE 10

void sortArrayUsingCounts(int a[], int n) {
	// Store count of all elements
	int count[MAX_SIZE] = {};
	for (int i = 0; i < n; ++i) {
		++count[a[i]];
	}
	int index = 0;
	for (int i = 0; i < MAX_SIZE; ++i) {
		while (count[i] > 0) {
			a[index++] = i;
			--count[i];
		}
	}
}

// Remove elements from arr[] at indexes ind1 and ind2
bool removeAndPrintResult(int a[], int n, int ind1, int ind2 = -1) {
	for (int i = n - 1; i >= 0; --i) {
		if (i != ind1 && i != ind2) cout << a[i];
	}
}

bool largest3Multiple(int a[], int n) {
	// Sum of all array element
	int sum = accumulate(a, a + n, 0);
	// Sum is divisible by 3 , no need to delete an element
	if (sum % 3 == 0) return true ;
	// Sort array element in increasing order
	sortArrayUsingCounts(arr, n);
	// Find reminder
	int remainder = sum % 3;
	// If remainder is '1', we have to delete either 1 element of remainder '1' or 2 elements of remainder '2'
	if (remainder == 1) {
		int rem_2[2];
		rem_2[0] = -1, rem_2[1] = -1;
		for (int i = 0 ; i < n ; ++i) {
			// Store first element of remainder '1'
			if (a[i] % 3 == 1) {
				removeAndPrintResult(arr, n, i);
				return true;
			}
			if (a[i] % 3 == 2) {
				// If this is first occurrence of remainder 2
				if (rem_2[0] == -1) rem_2[0] = i;
				// If second occurrence
				else if (rem_2[1] == -1) rem_2[1] = i;
			}
		}
		if (rem_2[0] != -1 && rem_2[1] != -1) {
			removeAndPrintResult(a, n, rem_2[0], rem_2[1]);
			return true;
		}
	}
	// If remainder is '2', we have to delete either 1 element of remainder '2' or 2 elements of remainder '1'
	else if (remainder == 2) {
		int rem_1[2];
		rem_1[0] = -1, rem_1[1] = -1;
		for (int i = 0; i < n; ++i) {
			// store first element of remainder '2'
			if (a[i] % 3 == 2) {
				removeAndPrintResult(arr, n, i);
				return true;
			}
			if (a[i] % 3 == 1) {
				// If this is first occurrence of remainder 1
				if (rem_1[0] == -1) rem_1[0] = i;
				// If second occurrence
				else if (rem_1[1] == -1) rem_1[1] = i;
			}
		}
		if (rem_1[0] != -1 && rem_1[1] != -1) {
			removeAndPrintResult(a, n, rem_1[0], rem_1[1]);
			return true;
		}
	}
	cout << "Not possible";
	return false;
}
