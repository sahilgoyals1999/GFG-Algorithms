// https://www.geeksforgeeks.org/compute-the-minimum-or-maximum-max-of-two-integers-without-branching/
// T.C => O(1)

#define CHARBIT 8
// (x-y) >> 31 == 0 => (x > y) else (y > x)

// Function to find minimum of x and y
int min(int x, int y) {
	return y + ((x - y) & ((x - y) >> (sizeof(int) * CHARBIT - 1)));
}

// Function to find maximum of x and y
int max(int x, int y)  {
	return x - ((x - y) & ((x - y) >> (sizeof(int) * CHARBIT - 1)));
}