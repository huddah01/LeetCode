/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        // Recursive idea: Use recursive function to do preorder traversal, so while visiting node
        // Store into output vector and then call the recursive function onto the children
        // Recursive idea is trivial
        /**
        // Initialize vector to return
        vector<int> visited;

        // Call the recursive function to perform preorder traversal
        preorderTraversal(root, visited);

        // Now that visited is populated return
        return visited;
        */
        // Iterative idea: We use a stack to iterate through the tree storing the children
        // In reverse order, this will produce the correct order for preorder traversal
        
        //  Initialize vector to return and stack to iterate through
        vector<int> visited;
        stack<Node*> nodeStack;

        // Push the first node onto stack
        nodeStack.push(root);

        // Then use a while loop and traverse through the tree
        while(!nodeStack.empty()) {
            // Hold temp variable for the top of stack
            Node* temp = nodeStack.top();
            // There is a case where we have 0 nodes thus we push a nullptr onto the stack
            if(temp == nullptr) {
                break;
            }
            // Visit the node
            visited.push_back(temp->val);
            // Now we pop the top of the stack and continue traversal
            nodeStack.pop();
            // Add children to the stack
            for(int i = temp->children.size() - 1; i >= 0; i--) {
                nodeStack.push(temp->children[i]);
            }
        }
        // When stack is empty all nodes have been visited and should be in the correct order
        return visited;
    }

    /**
     * Recursive function to perform preorder traversal and populate solution vector
     * Also remember to pass by reference for the vector for it to be populated
    void preorderTraversal(Node* root, vector<int> &visited) {
        // Base case when root is nullptr then we're done
        if(root == nullptr) {
            return;
        }
        // Visit the node
        visited.push_back(root->val);
        // Then recursive call the function the children nodes
        for(int i = 0; i < root->children.size(); i++) {
            preorderTraversal(root->children[i], visited);
        }
    }
    */
};
