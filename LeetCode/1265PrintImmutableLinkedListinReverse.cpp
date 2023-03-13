/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        // Since we can't traverse back wards we will push each element into a stack
        // Then print from the stack

        // Initialize a stack to later print
        stack<ImmutableListNode*> stack;

        // Push the nodes
        while(head != nullptr) {
            stack.push(head);
            // Iterate to next node
            head = head->getNext();
        }
        
        // Print from stack
        while(!stack.empty()) {
            stack.top()->printValue();
            // Pop to get next element
            stack.pop();
        }
    }
};
