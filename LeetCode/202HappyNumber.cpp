class Solution {
public:
    bool isHappy(int n) {
        // Since all numbers will be positive we use -1 as a default initial value
        int temp = -1;
        // Conver the number to a string
        string temp2 = to_string(n);
        // We use a hash map for it's built in find function to keep track of our cycle
        unordered_map<int, bool> temp3;

        // If we find a number that's been inserted into the hashmap we have completed the
        // Cycle so at that point we can just exit  the loop
        while(temp3.find(temp) == temp3.end()) {
            // Insert the number
            temp3[temp] = true;
            // Reset temp
            temp = 0;
            
            // Iterate through the string
            for(int i = 0; i < temp2.size(); i++) {
                /**
                // For debugging purposes
                cout << "temp2[i] is " << temp2[i] << " ";
                cout << "int(temp2[i]) is " << int(temp2[i]) - 48 << " ";
                cout << "temp2[i] squared is " << pow((int(temp2[i]) - 48), 2) << endl;
                */
                // We add the square of the number to the rest of the squares of the numbers
                // Note that we do the - 48 because of ascii values of char when we type cast
                // Back to an int
                temp += pow((int(temp2[i]) - 48), 2);
            }
            // Now we convert the new number to a string
            temp2 = to_string(temp);
            // If the total ever equals 1 we found a happy number
            if(temp == 1) {
                return true;
            }
        }
        // Otherwise false
        return false;
    }
};
