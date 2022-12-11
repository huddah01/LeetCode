class Solution {
public:
    int longestPalindrome(string s) {
        // Suggested idea: Use a vector/array to count frequencies of letters occuring, for the
        // Palindrome every character will have a partner to mirror it so we can add to our length
        // 2 everytime we find a pair, we will use floor division incase we get odd frequencies and
        // Will assign 1 unique center and assure this by using length % 2 to validate

        // Initialize vector for frequences and palindrome length
        int palLength = 0;
        // We use 123 because ascii values of letters go up to 122
        vector<int> freq(123, 0);

        // Iterate through string and count frequency of each letter
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]] += 1;
        }

        // After frequencies are counted we now add to palindrome length
        for(int i = 0; i < freq.size(); i++) {
            palLength += (freq[i] / 2) * 2;
            // Now we can check for a unique center and add it if applicable
            if(palLength % 2 == 0 && freq[i] % 2 == 1) {
                palLength += 1;
            }
        }
        // After all for loops return palindrome length
        return palLength;
    }
};
