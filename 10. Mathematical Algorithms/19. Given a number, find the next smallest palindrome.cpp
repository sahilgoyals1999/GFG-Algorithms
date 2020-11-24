// https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
// T.C => O(n)

int AreAll9s(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != 9) return 0;
	}
	return 1;
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
}

void generateNextPalindromeUtil(int a[], int n) {
	// find the index of mid digit
	int mid = n / 2;
	// end of left side is always 'mid -1'
	int i = mid - 1;
	// Beginning of right side depends if n is odd or even
	int j = (n % 2 == 1) ? mid + 1 : mid;
	// Initially, ignore the middle same digits
	while (i >= 0 && a[i] == a[j]) {
		--i;
		++j;
	}
	// Find if the middle digit(s) need to be incremented or not (or copying left side is not sufficient)
	// A bool variable to check if copy of left side to right is sufficient or not
	bool leftsmaller = false;
	if (i < 0 || a[i] < a[j]) leftsmaller = true;
	// Copy the mirror of left to tight
	while (i >= 0) {
		a[j] = a[i];
		--i;
		++j
	}
	// Handle the case where middle digit(s) must be incremented
	if (leftsmaller) {
		int carry = 1;
		// If there are odd digits, then increment the middle digit and store the carry
		if (n % 2 == 1) {
			num[mid] += carry;
			carry = num[mid] / 10;
			num[mid] %= 10;
		}
		i = mid - 1;
		j = (n % 2 == 1) ? mid + 1 : mid;
		// Add 1 to the rightmost digit of the left side, propagate the carry
		// towards MSB digit and simultaneously copying mirror of the left side to the right side.
		while (i >= 0) {
			num[i] += carry;
			carry = num[i] / 10;
			num[i] %= 10;
			num[j] = num[i]; // copy mirror to right
			++j;
			--i;
		}
	}
}

void generateNextPalindrome(int a[], int n) {
	// if all the digits are 9, simply print (1) (n-1 0's) (1).
	if (AreAll9s(a, n)) {
		cout << "1 "
		for (int i = 1; i <= n - 1; ++i) {
			cout << "0 ";
		}
		cout << "1";
	}
	else {
		generateNextPalindromeUtil(a, n);
		printArray(a, n);
	}
	cout << "\n";
}