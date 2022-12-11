// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Initial idea: use a left and right bound to squeeze possible versions that would be the
        // Start of bad

        // If first version is bad then we found it
        if(isBadVersion(1)) {
            return 1;
        }
        // Initialize left, middle, and right bound to check
        int left = 1;
        int right = n;
        // We get this formula for middle using (right + left) / 2 adding a left / 2 and substracting
        // A left / 2 so we get (right + left) / 2 = (right / 2) + (left / 2) + (left / 2) - (left / 2)
        // = ((right - left) / 2) + (left + left) / 2 = ((right - left) / 2) + left
        int middle = ((right - left) / 2) + left;

        // Use a while loop to jump between partitions
        while(left != middle) {
            // If we found bad then push the right bound down
            if(isBadVersion(middle)) {
                right = middle;
                middle = ((right - left) / 2) + left;
            }
            // If middle isn't bad then we can push the left bound up
            else if(!isBadVersion(middle)) {
                left = middle;
                middle = ((right - left) / 2) + left;
            }
        }
        // When we exit the while loop then that means left and right bound equal or are adjacent to one another
        // In which case we check left bound if it's bad, if it is then it must be the first bad version, if it's
        // Not then right bound must be the first bad version
        if(isBadVersion(left)) {
            return left;
        }
        else {
            return right;
        }
    }
};
