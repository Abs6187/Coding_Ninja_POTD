int repetition(string &s1, string &s2, int n1, int n2) {
    int current = 0;
    int occurrence = 0;

    // Loop through n1 repetitions of s1
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < s1.length(); j++) {
            if (s1[j] == s2[current]) {
                current++;
            }
            // If we've found a full occurrence of s2, reset the counter and increase occurrence
            if (current == s2.length()) {
                current = 0;
                occurrence++;
            }
        }
    }
    // Since s2 is repeated n2 times, divide occurrence by n2
    return occurrence / n2;
}
