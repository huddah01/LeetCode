/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Recursive idea: Use recursion to travel the tree, if both p and q are in the
        // Left or right subtree then we must continue to travel down the tree to find where
        // Split, the point at which they split is the LCA

        // Check if both in left
        if(root->val > p->val && root->val > q->val) {
            // Then we traverse into the left subtree
            return lowestCommonAncestor(root->left, p, q);
        }
        // Check if both in right
        else if(root->val < p->val && root->val < q->val) {
            // Then traverse into right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        // Otherwise they split at this point thus we can just return the current node
        else {
            return root;
        }
    }
};
