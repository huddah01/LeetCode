class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Initial idea have an iterator for the string s and only increment
        // When a duplicate character in t is found if the iterator reaches
        // To the size of string s then s is a subsequence of t
        // Iterator for s
        int sIndex = 0;
        // Iterate through t
        for(int i = 0; i < t.size(); i++) {
            // Matching character so we can increment s's iterator
            if(s[sIndex] == t[i]) {
                sIndex += 1;
            }
        }
        // Now check if we found a match for every letter in s
        if(sIndex == s.size()) {
            // Then s is a subsequence
            return true;
        }
        // Otherwise we couldn't find a match so s must not be a subsequence
        else {
            return false;
        }
    }
};
