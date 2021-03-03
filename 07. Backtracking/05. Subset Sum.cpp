// https://www.geeksforgeeks.org/subset-sum-backtracking-4/
//

static int total_nodes;

void printSubset(int A[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
	++total_nodes;
	if (target_sum == sum) {
		// We found subset
		printSubset(t, t_size);
		// Exclude previously added item and consider next candidate => Backtracking
		subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
		return;
	}
	// generate nodes along the breadth
	for (int i = ite; i < s_size; ++i) {
		t[t_size] = s[i];
		// consider next level node (along depth)
		subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
	}
}

void generateSubsets(int s[], int n, int target_sum) {
	int *tuplet_vector = (int *)malloc(n * sizeof(int));
	subset_sum(s, tuplet_vector, n, 0, 0, 0, target_sum);
	free(tuplet_vector);
}