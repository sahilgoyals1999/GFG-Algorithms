// https://www.geeksforgeeks.org/lucky-numbers/
// T.C => O(sqrt(n))

// intiallt position is n and
// at each iteration the count of numbers removed is n/i start with i with 2
// next_position = current_position – count of numbers removed

bool isLucky(int n) {
	static int i = 2;
	if (i > n) return true;
	if (n % i == 0) return 0;
	n -= n / i;
	++counter;
	return isLucky(n);
}