// https://www.geeksforgeeks.org/magic-square/
//

// Works only for odd value of n
void generateSquare(int n) {
	int magicSquare[n][n] = {};
	// Initialize position for 1
	int i = n / 2;
	int j = n - 1;
	// One by one put all values in magic square
	int num = 1;
	while (num <= n * n) {
		if (i == -1 && j == n) { // 3rd condition
			i = 0;
			j = n - 2;
		}
		else {
			// 1st condition helper if next number goes to out of square's right side
			if (j == n) j = 0;
			// 1st condition helper if next number is goes to out of square's upper side
			if (i < 0) i = n - 1;
		}
		if (magicSquare[i][j]) { // 2nd condition
			j -= 2;
			i++;
			continue;
		}
		else magicSquare[i][j] = num++; // set number
		j++;
		i--; // 1st condition
	}
	// Print magic square
	cout << "The Magic Square for n=" << n << "\nSum of each row or column is" << n * (n * n + 1) / 2 << ":\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			// setw(4) is used so that the matrix gets printed in a proper square fashion.
			cout << setw(4) << magicSquare[i][j] << " ";
		}
		cout << "\n";
	}
}