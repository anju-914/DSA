class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        int odd_cnt = 0;
        string M = "";
        vector<int> half(26, 0);
        
        // Count odds and set up the pool for the first half
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_cnt++;
                M = string(1, i + 'a');
            }
            half[i] = counts[i] / 2;
        }
        
        // A palindrome can have at most one character with an odd frequency
        if (odd_cnt > 1) {
            return "";
        }
        
        int n = s.length();
        int L = n / 2;
        string prefix = "";
        
        // Greedily build the first half of the palindrome
        for (int i = 0; i < L; ++i) {
            bool found = false;
            
            // Try characters from smallest ('a') to largest ('z')
            for (int c = 0; c < 26; ++c) {
                if (half[c] > 0) {
                    half[c]--; // Temporarily pick this character
                    
                    // Construct the MAXIMUM possible first half with the remaining characters
                    string H_temp = prefix + (char)(c + 'a');
                    for (int j = 25; j >= 0; --j) {
                        if (half[j] > 0) {
                            H_temp.append(half[j], (char)(j + 'a'));
                        }
                    }
                    
                    // Form the full max palindrome
                    string P_max = H_temp + M;
                    string H_rev = H_temp;
                    reverse(H_rev.begin(), H_rev.end());
                    P_max += H_rev;
                    
                    // If the maximum possible palindrome is greater than target, this choice is valid!
                    if (P_max > target) {
                        prefix += (char)(c + 'a');
                        found = true;
                        break; // Lock in this character and proceed to the next position
                    }
                    
                    // Backtrack and try the next character
                    half[c]++;
                }
            }
            
            // If no character works for the current position, it's impossible
            if (!found) {
                return "";
            }
        }
        
        // Construct the final lexicographically smallest valid palindrome
        string result = prefix + M;
        string pref_rev = prefix;
        reverse(pref_rev.begin(), pref_rev.end());
        result += pref_rev;
        
        return result > target ? result : "";
    }
};