class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initial idea: Start in the middle of the array if the target is less than then
        // Go to the middle of the left partition, if target is greater than then go to the
        // Middle of the right partition, if equal then return the index

        // Initialize a left and right bound to continue to get the middle
        int leftBound = 0;
        int rightBound = nums.size() - 1;
        int middle = (leftBound + rightBound) / 2;
        
        // While loop to jump partitions
        while(middle != leftBound) {
            // Found target
            if(target == nums[middle]) {
                return middle;
            }
            // If greater than then we push the leftBound up
            else if(target > nums[middle]) {
                leftBound = middle;
                middle = (leftBound + rightBound) / 2;
            }
            //  Otherwise we squeeze rightBound down
            else {
                rightBound = middle;
                middle = (leftBound + rightBound) / 2;
            }
        }

        // When middle equals leftBound then we squeezed the bounds to one or two digits
        // I.e. leftBound = middle = rightBound or leftBound = middle = (rightBound - 1)
        // So we check if target is equal to leftBound
        if(target == nums[leftBound]) {
            return leftBound;
        }
        // And check if target is equal to righBound
        if(target == nums[rightBound]) {
            return rightBound;
        }
        // If they don't then return error
        return - 1;
    }
};
