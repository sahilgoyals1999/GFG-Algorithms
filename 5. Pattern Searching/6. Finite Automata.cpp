// https://www.geeksforgeeks.org/pattern-searching-set-5-efficient-constructtion-of-finite-automata/
// T.C =>  O(m * NO_OF_CHARS)

#define NO_OF_CHARS 256

void computeTransFun(string pat, int TF[][NO_OF_CHARS]) {
	int i, lps = 0, x;
	int m = pat.length();
	// Fill entries in first row
	for (x = 0; x < NO_OF_CHARS; ++x) {
		TF[0][x] = 0;
	}
	TF[0][pat[0]] = 1;
	// Fill entries in other rows
	for (i = 1; i <= m; ++i) {
		// Copy values from row at index lps
		for (x = 0; x < NO_OF_CHARS; ++x) {
			TF[i][x] = TF[lps][x];
		}
		// Update the entry corresponding to this character
		TF[i][pat[i]] = i + 1;
		// Update lps for next row to be filled
		if (i < m) lps = TF[lps][pat[i]];
	}
}

void search(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();
	int TF[m + 1][NO_OF_CHARS];
	computeTransFun(pat, TF);
	// process text over FA.
	int i, j = 0;
	for (i = 0; i < n; i++) {
		j = TF[j][txt[i]];
		if (j == m) {
			cout << i - m + 1 << "\n";
		}
	}
}