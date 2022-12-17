class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 2 pass using erase and editing i and string length

        // Capture size for editing during for loop
        int sLen = s.size();
        int tLen = t.size();

        // First pass for the s string
        for(int i = 0; i < sLen; i++) {
            // If we find a backspace character
            if(s[i] == '#') {
                // If there's a character to delete we delete that
                if(i > 0) {
                    s.erase(i - 1, 2);
                    // We make sure to deincrement length and i so we don't skip
                    // Over characters of the string
                    sLen -= 2;
                    i -= 2;
                }
                else {
                    // If there's no character to delete then just delete the
                    // Backspace character
                    s.erase(i, 1);
                    // Again making sure to deincrement so we don't skip any characters
                    sLen -= 1;
                    i -= 1;
                }
            }
        }

        // Repeat this process for the t string
        for(int i = 0; i < tLen; i++) {
            if(t[i] == '#') {
                if(i > 0) {
                    t.erase(i - 1, 2);
                    tLen -= 2;
                    i -= 2;
                }
                else {
                    t.erase(i, 1);
                    tLen -= 1;
                    i -= 1;
                }
            }
        }
        
        // If they equal true
        if(s == t) {
            return true;
        }
        // Otherwise false
        return false;
    }
};
