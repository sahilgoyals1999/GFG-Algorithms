// https://www.geeksforgeeks.org/find-the-largest-multiple-of-2-3-and-5/
// T.C => O(n)

// Since the number has to be divisible by 2 and 5,
// it has to have last digit as 0.
// So if the given array doesn’t contain any zero,
// then no solution exists.

// Once a 0 is available, extract 0 from the given array.
// Only thing left is, the number should be is divisible by 3
// and the largest of all. Which has been discussed already above.