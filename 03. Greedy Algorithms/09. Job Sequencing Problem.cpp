// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// T.C => O(n^2)

bool comp(Job a, Job b) {
	return a.profit > b.profit;
}

pair<int, int> JobScheduling(Job a[], int n) {
	// sort in dec. order of profit
	sort(a, a + n, comp);
	vector<int> result(n);        // To store result (Sequence of jobs)
	vector<bool> slot(n, false);  // To keep track of free time slots
	for (int i = 0; i < n; ++i) {
		// Find a free slot for this job (we startfrom the last possible slot)
		for (int j = min(n, a[i].dead) - 1; j >= 0; --j) {
			// Free slot found
			if (!slot[j]) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
	pair<int, int> ans(0, 0);
	for (int i = 0; i < n; i++) {
		if (slot[i]) {
			++ans.first;
			ans.second += a[result[i]].profit;
		}
	}
	return ans;
}