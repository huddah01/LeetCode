class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Initial idea: map every letter in s to every letter in t
        // If duplicates spotted then check for different mapping
        // If different mapping then return false immediately
        // To ensure one-to-one mapping use two maps since finding values
        // Is common and iteratoring through the map everytime would be slow
        // Map to store values
        unordered_map<char, char> mapStoT;
        unordered_map<char, char> mapTtoS;
        // Create an iterator for readability
        unordered_map<char, char>::iterator stItr;
        unordered_map<char, char>::iterator tsItr;
        for(int i = 0; i < s.size(); i++) {
            // Check if there is a duplicate from s to t
            stItr = mapStoT.find(s[i]);
            tsItr = mapTtoS.find(t[i]);
            if(stItr != mapStoT.end()) {
                // Duplicate found from s to t so check if it's a different mapping
                if(stItr->second != t[i]) {
                    // Different mapping so return false
                    return false;
                }
            }
            // No duplicate so map both from s to t
            else {
                mapStoT[s[i]] = t[i];
            }
            // Check if duplicate for t to s now
            if(tsItr != mapTtoS.end()) {
                // Duplicate found from t to s so same check
                if(tsItr->second != s[i]) {
                    // Different mapping so return false
                    return false;
                }
            }
            // No duplicate so map both from s to t and vice versa
            else {
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            }
        }
        // If we successfully exit for loop then s and t are isomorphic
        return true;
    }
};
