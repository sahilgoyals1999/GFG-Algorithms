// https://www.geeksforgeeks.org/efficient-way-to-multiply-with-7/
// T.C => O(1)

// First left shift the number by 3 bits (you will get 8n) then
// subtract the original number from the shifted number
// and return the difference (8n – n)

long multiplyBySeven(long n)  {
	return ((n << 3) - n);
}
