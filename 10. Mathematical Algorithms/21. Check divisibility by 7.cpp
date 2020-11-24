// https://www.geeksforgeeks.org/divisibility-by-7/
// T.C => O(d)

// a = num / 10 , b = num % 10;
// 10*a + b          any number can be written like this
// 20*a + 2.b        multiply by 2
// 21*a - a + 2*b
// -a + 2*b          21*a is already multiple of 7, so remove it
// a - 2*b           multiply by -1, so just check for this
int isDivisibleBy7(int num) {
	// If number is negative, make it positive
	if (num < 0) return isDivisibleBy7(-num);
	// Base cases
	if (num == 0 || num == 7) return 1;
	if (num < 10) return 0;
	int a = num / 10;
	int b = num  - a * 10;
	return isDivisibleBy7(a - 2 * b);
}