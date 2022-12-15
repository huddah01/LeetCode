class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Use a hashmap to find complements, we map the number to it's complement
        // If we find the complement in the hashmap then we found our solution

        // Create a solution vector and a hashmap for complements
        vector<int> soln;
        unordered_map<int, int> complements;

        // Insert the elements map to it's index
        for(int i = 0; i < nums.size(); i++) {
            complements[nums[i]] = i;
        }

        // Now iterate through the list 
        for(int i = 0; i < nums.size(); i++) {
            // Store the complement
            int complement = target - nums[i];
            // Make sure that the complement exists within the hashmap and that the index of the
            // Complement index must also not be the same as the current index
            if(complements.find(complement) != complements.end() && i != complements[complement]) {
                // We push the index into the solution vector then break because we have exactly
                // One solution
                soln.push_back(i);
                soln.push_back(complements[complement]);
                break;
            }
        }
        // Return the solution vector
        return soln;
    }
};
