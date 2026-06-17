class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);

        // Forward pass: record length after each step
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i]))        len[i+1] = len[i] + 1;
            else if (s[i] == '*')    len[i+1] = max(0LL, len[i] - 1);
            else if (s[i] == '#')    len[i+1] = len[i] * 2;
            else                       len[i+1] = len[i]; // '%'
        }

        if (k >= len[n]) return '.';

        // Backward pass: trace where k came from
        for (int i = n - 1; i >= 0; i--) {
            long long L = len[i]; // length BEFORE this op

            if (isalpha(s[i])) {
                if (k == L) return s[i]; // k points exactly at this letter
                // else k unchanged (letter was appended after position k)
            } else if (s[i] == '*') {
                // removal: k unchanged going backwards
            } else if (s[i] == '#') {
                k = k % L; // both halves identical, fold k back
            } else { // '%'
                k = L - 1 - k; // mirror the position
            }
        }

        return '.'; // unreachable if k < len[n]
    }
};