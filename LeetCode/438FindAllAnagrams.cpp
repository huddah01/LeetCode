class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Use the sliding window method with a hash map

        // Initialize solution vector
        vector<int> soln;
        // Check edge case where s is smaller than p
        if(s.size() < p.size()) {
            // Return empty vector
            return soln;
        }
        // Initialize two hashmaps, one for s and one for p
        unordered_map<char, int> sFreq;
        unordered_map<char, int> pFreq;

        // build the pFreq map to later use to compare during sliding window
        for(int i = 0; i < p.size(); i++) {
            if(pFreq.find(p[i]) == pFreq.end()) {
                pFreq[p[i]] = 1;
            }
            else {
                pFreq[p[i]] += 1;
            }
        }

        // Now we begin sliding window on s
        for(int i = 0; i < s.size(); i++) {
            if(sFreq.find(s[i]) == sFreq.end()) {
                sFreq[s[i]] = 1;
            }
            else {
                sFreq[s[i]] += 1;
            }
            // We can start removing from the left and adding to the right
            if(i >= p.size()) {
                // In case char has frequency 1
                if(sFreq[s[i - p.size()]] == 1) {
                    sFreq.erase(s[i - p.size()]);
                }
                // Else we can just deincrement
                else{
                    sFreq[s[i - p.size()]] -= 1;
                }
            }
            // Compare the hashmaps to see if they share equal key-value pairs
            if(sFreq == pFreq) {
                // Then we can add the index to the solution vector
                soln.push_back(i - p.size() + 1);
            }
        }
        // When the for loop ends we can just return the solution vector
        return soln;
    }
};
