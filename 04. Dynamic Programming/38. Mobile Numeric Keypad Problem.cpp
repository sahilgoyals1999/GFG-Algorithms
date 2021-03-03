// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/
// T.C => O(n), S.C => O(n)

#define ll long long
// Return count of all possible numbers of length n in a given numeric keyboard
int getCount(int n) {
	char keypad[4][3] =
	{	{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
		{'*', '0', '#'}
	};
	if (n <= 0) return 0;
	if (n == 1) return 10;
	// left, up, right, down move from current location
	int row[] = {0, 0, -1, 0, 1};
	int col[] = {0, -1, 0, 1, 0};
	// count[i][j] => number count starting with digit i and length j
	ll count[10][n + 1];
	// count numbers starting with digit i and of lengths 0 and 1
	for (int i = 0; i <= 9; ++i) {
		count[i][0] = 0;
		count[i][1] = 1;
	}
	// Bottom up - Get number count of length 2, 3, 4, ... , n
	for (int k = 2; k <= n; ++k) {
		for (int i = 0; i < 4; ++i) { // Loop on keypad row
			for (int j = 0; j < 3; ++j) { // Loop on keypad column
				// Process for 0 to 9 digits
				if (keypad[i][j] != '*' && keypad[i][j] != '#') {
					// Here we are counting the numbers starting with
					// digit keypad[i][j] and of length k keypad[i][j]
					// will become 1st digit, and we need to look for (k-1) more digits
					int num = keypad[i][j] - '0';
					count[num][k] = 0;
					// move left, up, right, down from current location
					// and if new location is valid, then get number
					// count of length (k-1) from that new digit and
					// add in count we found so far
					for (int move = 0; move < 5; ++move) {
						int ro = i + row[move];
						int co = j + col[move];
						if (ro >= 0 && ro <= 3 && co >= 0 && co <= 2 && keypad[ro][co] != '*' && keypad[ro][co] != '#') {
							int nextNum = keypad[ro][co] - '0';
							count[num][k] += count[nextNum][k - 1];
						}
					}
				}
			}
		}
	}
	// Get count of all possible numbers of length "n" starting with digit 0, 1, 2, ..., 9
	ll totalCount = 0;
	for (int i = 0; i <= 9; ++i) {
		totalCount += count[i][n];
	}
	return totalCount;
}