// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
// T.C => O(v)

int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
int n = 9;

void find_min(int v) {
	sort(deno, deno + n);
	vector<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		while (v >= deno[i]) {
			v -= deno[i];
			ans.push_back(deno[i]);
		}
	}
	for (int &x : ans) {
		cout << x << " ";
	}
}