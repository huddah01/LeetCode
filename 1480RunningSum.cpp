class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Vector to return
        vector<int> soln;
        // int variable for math
        int counter = 0;
        // For loop adding up with counter and continuously adding at every iteration
        for(int i = 0; i <  nums.size(); i++) {
            counter += nums[i];
            soln.push_back(counter);
        }
        // Return solution vector
        return soln;
    }
};
