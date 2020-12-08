// https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/
// T.C => O(1)

// Function to check power of two
bool isPowerofTwo(long long n) {
	return (n && !(n & (n - 1)));
}