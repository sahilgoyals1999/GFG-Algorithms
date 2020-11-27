// https://www.geeksforgeeks.org/find-excel-column-name-given-number/
// T.C => O(n)

// Function to print Excel column name for a given column number
void printString(int n) {
	vector<char> str(50); // To store result (Excel column name)
	int i = 0;
	while (n > 0) {
		// Find remainder
		int rem = n % 26;
		// If remainder is 0, then a 'Z' must be there in output
		if (rem == 0) {
			str[i++] = 'Z';
			n = (n / 26) - 1;
		}
		else {
			str[i++] = 'A' + (rem - 1);
			n = n / 26;
		}
	}
	for (int j = i; j >= 0; --j) {
		cout << str[j];
	}
	cout << "\n";
}