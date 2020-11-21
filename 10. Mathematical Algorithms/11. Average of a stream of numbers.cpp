// https://www.geeksforgeeks.org/average-of-a-stream-of-numbers/
// T.C => O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n, sum = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			sum += x;
			cout << sum / i << " ";
		}
		cout << "\n";
		--t;
	}
	return 0;
}