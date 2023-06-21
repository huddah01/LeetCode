class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute force approach: Have a temporary int vector to copy nums1 and iterate
        // both lists using pointers to hold the place insert into the vector accordingly
        
        // Initialize vector to store and pointer variables
        vector<int> temp = nums1;
        int pointer1 = 0;
        int pointer2 = 0;

        // Loop through both lists
        for(int i = 0; i < n + m; i++)  {
            // Edge case for boundaries
            if(pointer1 == m) {
                nums1[i] = nums2[pointer2];
                pointer2++;
            }
            else if(pointer2 == n) {
                nums1[i] = temp[pointer1];
                pointer1++;
            }
            // Otherwise compare and assign the lesser
            else {
                if(temp[pointer1] <= nums2[pointer2]) {
                    nums1[i] = temp[pointer1];
                    pointer1++;
                }
                else {
                    nums1[i] = nums2[pointer2];
                    pointer2++;
                }
            }
        }
    }
};
