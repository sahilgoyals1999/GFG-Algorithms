// https://www.geeksforgeeks.org/pascal-triangle/
// T.C => O(n^2), S.C => O(1)

// every element is C(line, i) start with line =0 and i=0;
void printPascal(int n) {
	for (int line = 1; line <= n; line++) {
		int C = 1; // used to represent C(line, i)
		for (int i = 1; i <= line; ++i) {
			// The first value in a line is always 1
			cout << C << " ";
			C = C * (line - i) / i;
		}
		cout << "\n";
	}
}