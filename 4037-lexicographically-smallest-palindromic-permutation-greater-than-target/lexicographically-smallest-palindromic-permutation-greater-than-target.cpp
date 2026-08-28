class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        // Step 1: Count frequency of every character
        int n = s.size();
        vector<int> hsh(26, 0);

        for (int i = 0; i < n; i++) {
            hsh[s[i] - 'a']++;
        }

        // Step 2: Check whether palindrome is possible
        // Also prepare half frequencies
        string ans = s;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (hsh[i] % 2 != 0) {
                odd++;
                // Odd frequency character goes to middle
                ans[n / 2] = char('a' + i);
            }

            // Only half characters are needed for left half
            hsh[i] /= 2;
        }

        // More than one odd frequency
        // means palindrome is impossible
        if (odd > 1) {
            return "";
        }

        // Step 3: Match target's left half
        // as much as possible
        int p = 0;
        while (p < n / 2 && hsh[target[p] - 'a']) {
            hsh[target[p] - 'a']--;
            p++;
        }

        // Step 4: Start backtracking from the right
        int start = min(n - 1, p);
        for (int i = start; i >= 0; i--) {

            // Step 5: Handle middle position
            // for odd length
            if (i == n / 2) {
                for (int j = 0; j < n / 2; j++) {
                    ans[j] = target[j];
                    ans[n - 1 - j] = target[j];
                }

                if (ans > target) {
                    return ans;
                }
                continue;
            }

            // Step 6: Current target character
            int b = target[i] - 'a';

            // Step 7: If this character was already
            // consumed while matching prefix,
            // put it back
            if (i < p) {
                hsh[b]++;
            }

            // Step 8: Find the smallest character
            // greater than target[i]
            int idx = -1;
            for (int c = b + 1; c < 26; c++) {
                if (hsh[c]) {
                    hsh[c]--;
                    idx = c;
                    break;
                }
            }
            // No greater character available
            if (idx == -1) {
                continue;
            }
            // Step 9: Keep prefix same as target
            for (int j = 0; j < i; j++) {
                ans[j] = target[j];
            }
            // Step 10: Put greater character
            // at current position
            ans[i] = char('a' + idx);

            // Step 11: Fill remaining characters
            // in ascending order
            int k = i + 1;

            for (int c = 0; c < 26; c++) {
                while (k < n && hsh[c]) {
                    ans[k] = char(c + 'a');
                    k++;
                    hsh[c]--;
                }
            }

            // Step 12: Mirror the left half
            // to create palindrome
            for (int j = 0; j < n / 2; j++) {
              ans[n - 1 - j] = ans[j];
            }

            // We found the lexicographically
            // smallest valid answer
            return ans;
        }

        // No valid palindrome greater than target
        return "";
    }
};