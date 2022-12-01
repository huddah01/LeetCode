class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /**
        // Brute force approach of checking every element to see if it is a valid
        // pivot index
        // Leftsum and rightsum counters
        int leftsum;
        int rightsum;
        for(int i = 0; i < nums.size(); i++) {
            // Reset leftmost and rightmost sums
            leftsum = 0;
            rightsum = 0;
            // Generic case
            // Checking left sum
            for(int j = 0; j < i; j++) {
                leftsum += nums[j];
            }
            // Checking right sum
            for(int j = i + 1; j < nums.size(); j++) {
                rightsum += nums[j];
            }
            if(leftsum == rightsum) {
                return i;
            }
            */
        // Suggested solution of calculating overall sum then using sum - nums[i] - leftsum to
        // find right sum
        // Counter variables
        int sum = 0;
        int leftsum = 0;
        int rightsum;
        // Calculating overall sum;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // Now we go through nums to find pivot index
        for(int i = 0; i < nums.size(); i++) {
            // Increment left sum except for 0 index
            if(i != 0) {
                leftsum += nums[i - 1];
            }
            // Now compare using the suggested formula
            rightsum = sum - nums[i] - leftsum;
            if(leftsum == rightsum) {
                return i;
            }
        }
        // No pivot index so return -1
        return -1;
    }
};
