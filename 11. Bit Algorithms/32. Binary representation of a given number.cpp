// https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
// T.C => O(log(n))

string getBinaryRep(int n) {
	unsigned int i = (1 << 31); // pow(2,31);
	string ans;
	while (i > 0) {
		ans += ((n & i) ? "1" : "0");
		i /= 2;
	}
	return ans;
}