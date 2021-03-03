// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1#
// T.C => O(log(n) + k)

vector<int> printKClosest(vector<int> a, int n, int k, int x) {
	vector<int> ans;
	int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
	int left = pos - 1;
	int right = pos;
	if (a[pos] == x) ++right;
	while (k > 0 && left >= 0 && right < n) {
		if (x - a[left] < a[right] - x) ans.push_back(a[left--]);
		else ans.push_back(a[right++]);
		--k;
	}
	while (k > 0 && left >= 0) {
		ans.push_back(a[left--]);
		--k;
	}
	while (k > 0 && right < n) {
		ans.push_back(a[right++]);
		--k;
	}
	return ans;
}