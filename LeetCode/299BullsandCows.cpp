class Solution {
public:
    string getHint(string secret, string guess) {
        // Too slow
        /*
        // Use hashmap to keep track of frequencies and integer counters
        unordered_map<char, int> secretFreq;
        unordered_map<char, int> guessFreq;
        int bull = 0;
        int cow = 0;

        // Use a for loop to populate frequencies, we don't populate if we find bulls
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                bull++;
            }
            // If character not within frequency list yet then insert
            if(secretFreq.find(secret[i]) == secretFreq.end()) {
                secretFreq[secret[i]] = 1;
            }
            // If it is increment by 1
            else {
                secretFreq[secret[i]] += 1;
            }
            if(guessFreq.find(guess[i]) == guessFreq.end()) {
                guessFreq[guess[i]] = 1;
            }
            else {
                guessFreq[guess[i]] += 1;
            }
        }
        unordered_map<char, int>::iterator itr;
        for(itr = guessFreq.begin(); itr != guessFreq.end(); itr++) {
            if(secretFreq.find(itr->first) == secretFreq.end()) {
                continue;
            }
            while(secretFreq[itr->first] != 0 || itr->second != 0) {
                secretFreq[itr->first] -= 1;
                itr->second -= 1;
                cow++;
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
        */

        // Use hashmap to keep track of frequencies and integer counters
        unordered_map<char, int> secretFreq;
        int bull = 0;
        int cow = 0;

        // Populate secret frequencies
        for(int i = 0; i < secret.size(); i++) {
            if(secretFreq.find(secret[i]) == secretFreq.end()) {
                secretFreq[secret[i]] = 1;
            }
            else {
                secretFreq[secret[i]] += 1;
            }
        }

        // Now iterate through guess
        for(int i = 0; i < guess.size(); i++) {
            // When we find a match we increment bull
            if(secret[i] == guess[i]) {
                bull++;
                // Decrease the frequency for secret
                secretFreq[secret[i]] -= 1;
            }
        }
        // Second loop to check for cows
        for(int i = 0; i  < guess.size(); i++) {
            // If the character exists and wasn't used in a bull match
            if(secretFreq.find(guess[i]) != secretFreq.end() && secret[i] != guess[i]) {
                // If there still exists the character
                if(secretFreq[guess[i]] != 0) {
                    // We increment cow and reduce frequency to signify a match
                    cow++;
                    secretFreq[guess[i]] -= 1;
                }
            }
        }
        // Then we return the hint parsing the integer counters
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
