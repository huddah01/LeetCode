class Solution {
public:
    int characterReplacement(string s, int k) {
        // We use a sliding window approach as well as binary search to find the
        // Longest substring

        // Initialize min to be 1 and max to be 1 more than the length of the string
        int min = 1;
        int max = s.size() + 1;

        // When min and max are next to each other then we can exit the while loop
        while(min + 1 < max) {
            // Mid is (min + max) / 2
            int mid = min + ((max - min) / 2);

            // We use a helper method to check if there is a valid substring of length
            // Mid
            if(helper(s, mid, k)) {
                // If true we push min up as the longest substring as at least mid
                // From what we found in helper and we now explore the right half
                min = mid;
            }
            // Otherwise we bring max down as we know no valid substring exists at mid
            // And now we explore the left half
            else {
                max = mid;
            }
        }
        // After we exit the while loop the longest substring length will be squeezed to min
        return min;
    }
    
    /*
    // Helper method that see if the substring is valid, we use the sliding window method with 
    // A frequency vector to go through the array and check if substring length - max frequency <= k
    // Which signifies that the substring is valid with k or less changes
    */
    bool helper(string s, int substringLength, int k) {
        // Initialize frequency map, a max frequency, and start
        vector<int> freqVec(26, 0);
        int maxFreq = 0;
        int start = 0;

        for(int end = 0; end < s.length(); end += 1) {
            // Increment the frequency
            freqVec[s[end] - 'A'] += 1;

            // If the window exceeds the substring length then we can move the window
            if(end + 1 - start > substringLength) {
                // Deincrement leftmost pointer of window
                freqVec[s[start] - 'A'] -= 1;
                // Then move start pointer up
                start += 1;
            }
            // Check for max frequency
            if(maxFreq < freqVec[s[end] - 'A']) {
                maxFreq = freqVec[s[end] - 'A'];
            }
            // Check for valid substring
            if(substringLength - maxFreq <= k) {
                return true;
            }
        }
        // If we exit the for loop then there doesn't exist a valid substring with length
        // substringLength so we return false
        return false;
    }

};
