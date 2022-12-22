class Solution {
public:
    string decodeString(string s) {
        /**
        // Doesn't work because we can't account for case where there is no square brackets
        // On the character
        // Initialize solution string to return
        string solnStr = "";
        string tempStr = "";
        string tempInt = "";
        string tempStr2 = "";

        //Initialize stack to use in algorithm
        stack<char> stack;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ']') {
                stack.push(s[i]);
            }
            else {
                tempStr = "";
                while(!stack.empty()) {
                    if(stack.top() != '[') {
                        tempStr = stack.top() + tempStr;
                        stack.pop();
                    }
                    else {
                        stack.pop();
                        tempInt = "";
                        while(!stack.empty() && isdigit(stack.top())) {
                            tempInt = stack.top() + tempInt;
                            stack.pop();
                        }
                        tempStr2 = "";
                        int tempInt2 = stoi(tempInt);
                        for(int j = 0; j < tempInt2; j++) {
                            tempStr2 = tempStr2 + tempStr;
                        }
                        tempStr = tempStr2;
                    }
                }
                solnStr = solnStr + tempStr;
            }
        }
        return solnStr;
        */
        // Initialize stack for the algorithm and solution string to return later
        stack<char> stack;
        string solnStr = "";
        
        // Go through the encoded string
        for(int i = 0; i < s.size(); i++) {
            // If we find a closing bracket then we can the decode the string
            if(s[i] == ']') {
                // We have a temp string to decode
                string tempStr = "";
                // While we don't see an open bracket we add to the temp string
                while(stack.top() != '[') {
                    tempStr = stack.top() + tempStr;
                    stack.pop();
                }
                // Pop the open bracket
                stack.pop();
                // Now we capture the integer value
                string tempInt = "";
                while(!stack.empty() && isdigit(stack.top())) {
                    tempInt = stack.top() + tempInt;
                    stack.pop();
                }
                int tempInt2 = stoi(tempInt);
                // Then we repeat the temp string temp int times because that's how the encoding works
                for(int j = 0; j < tempInt2; j++) {
                    for(int k = 0; k < tempStr.size(); k++) {
                        stack.push(tempStr[k]);
                    }
                }
            }
            // Otherwise we can just push onto the stack
            else {
                stack.push(s[i]);
            }
        }
        // The stack was made with the decoded string in reverse so we pop the stack and prepend
        while(!stack.empty()) {
            solnStr = stack.top() + solnStr;
            stack.pop();
        }
        // Return the solution string
        return solnStr;
    }
};
