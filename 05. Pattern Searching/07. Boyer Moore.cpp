// https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
// T.C => for avg case: O(n/m), for worst case : O(n*m)

// Boyer Moore's bad character heuristic
# NO_OF_CHARS 256
void badCharHeuristic(string pat, int badchar[NO_OF_CHARS]) {
    int m = pat.length();
    // Initialize all occurrences as -1
    for (int i = 0; i < NO_OF_CHARS; ++i) {
        badchar[i] = -1;
    }
    // Fill the actual value of last occurrence of a character
    for (int i = 0; i < m; ++i) {
        badchar[str[i]] = i;
    }
}

void search(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, badchar);
    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;
        // Keep reducing index j of pattern while characters of pattern
        // and text are matching at this shift s
        while (j >= 0 && pat[j] == txt[s + j]) {
            --j;
        }
        // If the pattern is present at current shift,
        // then index j will become -1 after the above loop
        if (j < 0) {
            cout << s << "\n";
            // Shift the pattern so that the next character in text
            // aligns with the last occurrence of it in pattern.
            // The condition s+m < n is necessary for the case when pattern occurs at the end of text
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else {
            // Shift the pattern so that the bad character in text aligns with the
            // last occurrence of it in pattern.
            // The max function is used to make sure that we get a positive shift.
            // We may get a negative shift if the last occurrence of bad character
            // in pattern is on the right side of the current character
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}