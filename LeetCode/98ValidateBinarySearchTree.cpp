/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Recursion idea: Use recursion on the left and right child at each node then we check
        // If each node follows the rule of a binary search tree as soon as we see one error
        // We can return false, otherwise we return true
        // We need a helper method to keep track of limits because there are edge cases
        // Where the node will satisfy the rules for itself but not for the root node
        
        // Use helper method we start with no upper or lower limits
        return helper(root, nullptr, nullptr);
    }
    /*
    // Helper method that will validate each node
    */
    bool helper(TreeNode* root, TreeNode* lowLim, TreeNode* upLim) {
        // Edge case of empty tree
        if(root == nullptr) {
            return true;
        }

        // Check node is between the upper and lower limit nullptr signifying no limit
        if(lowLim != nullptr) {
            if(root->val <= lowLim->val) {
                return false;
            }
        }
        if(upLim != nullptr) {
            if(root->val >= upLim->val) {
                return false;
            }
        }

        // Now we run recursion
        // For checking the right child, the parent will be the new lower limit and Upper
        // Limit stays the same; for the left child, the parent will be the new upper limit
        // And lower limit stays the same; This is because as you traverse right the node
        // Has to be bigger so we push the lower limit up, as we traverse left the node
        // Has to be smaller so we push the upper limit down, we can traverse both left
        // And right in the same path so we conserve those limits as we go
        return (helper(root->right, root, upLim) && helper(root->left, lowLim, root));
    }
};
