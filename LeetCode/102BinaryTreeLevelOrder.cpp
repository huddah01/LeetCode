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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Iterative idea: We can try using a queue to store the elements of the tree and visit
        // The nodes in level order traversal
        /**
        // Initialize return vector and queue for traversal, use a counter variable to keep
        // Track of level length
        vector<vector<int>> visited;
        queue<TreeNode*> nodeQueue;
        int levelLength = 0;

        // Edge case of 0 nodes
        if(root == nullptr) {
            return visited;
        }

        // Push first element into queue
        nodeQueue.push(root);

        // Now traverse through the tree with a while loop
        while(!nodeQueue.empty()) {
            // Create an int vector that we will add nodes of current level to
            vector<int> currLevel;
            // Get the level length with current queue size
            levelLength = nodeQueue.size();
            // Go through all nodes of current level
            for(int i = 0; i < levelLength; i++) {
                // Hold temporary variable to top of queue
                TreeNode* temp = nodeQueue.front();
                // Visit the node
                currLevel.push_back(temp->val);
                // Now we pop
                nodeQueue.pop();
                // Add any children from the node we just visited to the queue
                // This also shows why we need an int variable to keep track of
                // Level length other queue size would change and we would be stuck
                // In the loop until the queue is empty
                if(temp->left != nullptr) {
                    nodeQueue.push(temp->left);
                }
                if(temp->right != nullptr) {
                    nodeQueue.push(temp->right);
                }
            }
            // When we exit the for loop that is the end of all nodes of current level so
            // We can add that vector to our solution
            visited.push_back(currLevel);
        }
        // Once we exit the while loop we should have visited every node and so return solution
        return visited;
        */
        // Recursive idea: Use a recursive function to traverse through the tree, level order traversal
        // Will require us to use a levels variable to keep track of what level we are on

        // Initialize vector of vectors to return and int variable to keep track of current level
        vector<vector<int>> visited;
        int level = 0;
        // Check edge case of 0 nodes
        if(root == nullptr) {
            return visited;
        }
        // Otherwise call our recursive function
        traversal(visited, root, level);
        return visited;
    }
    /*
    // Helper function to solve level order traversal recursively
    */
    void traversal(vector<vector<int>> &visited, TreeNode* root, int level) {
        // Used to see if we need a vector to start for the current level
        if(visited.size() == level) {
            // Add an int vector to our vector of vectors
            vector<int> currLevel;
            visited.push_back(currLevel);
        }
        // Visit the node, since we use level to ensure nodes get sent
        // To the correct vector we don't need a queue for correct traversal
        // To get the correct output
        visited[level].push_back(root->val);
        // Now call recursively on the children
        if(root->left != nullptr) {
            // We add a level since we move onto the next level
            traversal(visited, root->left, level + 1);
        }
        if(root->right != nullptr) {
            traversal(visited, root->right, level + 1);
        }
    }
};
