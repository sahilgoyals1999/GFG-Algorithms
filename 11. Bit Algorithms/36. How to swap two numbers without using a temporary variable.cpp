// https://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
// T.C => O(1)

void swap(int &a, int &b) {
	//same as a = a + b
	a = (a & b) + (a | b);
	//same as b = a - b
	b = a + (~b + 1);
	//same as a = a - b
	a = a + (~b + 1);
}