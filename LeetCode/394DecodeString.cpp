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
        stack<char> stack;
        string solnStr = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ']') {
                string tempStr = "";
                while(stack.top() != '[') {
                    tempStr = stack.top() + tempStr;
                    stack.pop();
                }
                stack.pop();
                string tempInt = "";
                while(!stack.empty() && isdigit(stack.top())) {
                    tempInt = stack.top() + tempInt;
                    stack.pop();
                }
                int tempInt2 = stoi(tempInt);
                //int currSize = tempStr.size();
                for(int j = 0; j < tempInt2; j++) {
                    for(int k = 0; k < tempStr.size(); k++) {
                        stack.push(tempStr[k]);
                    }
                }
            }
            else {
                stack.push(s[i]);
            }
        }
        while(!stack.empty()) {
            solnStr = stack.top() + solnStr;
            stack.pop();
        }
        return solnStr;
    }
};
