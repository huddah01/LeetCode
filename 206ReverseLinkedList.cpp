/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initial idea: A stack is a lifo data structure that could 
        // reverse the list, i.e. add the nodes in the stack one by one
        // then pop the stack and new list created will be the reversed
        /**
        // Get an unchanging reference to the solution linked list
        ListNode* reversedList = new ListNode(-1);
        // Iterator to capture nodes from the stack
        ListNode* listItr = reversedList;
        // Initialize a stack to reverse
        stack<ListNode*> stack;
        // While loop to push to stack
        while(head != nullptr) {
            // Use new node to avoid linked list in a cycle error
            stack.push(new ListNode(head->val));
            // Iterate head
            head = head->next;
        }
        // When exited first while loop we can now pop the stack and start
        // uno reversing
        while(!stack.empty()) {
            listItr->next = stack.top();
            // Iterate the list and pop the stack
            listItr = listItr->next;
            stack.pop();
        }
        // When exited second while loop then completed so return reference
        return reversedList->next;
        */
        // Suggested idea: Use variables to hold previous node of the list and
        // change the list at each step with a one pass through the linked list
        // Initialize previous and iterator variables
        ListNode* prev = nullptr;
        ListNode* itr = head;
        while(itr != nullptr) {
            // Create a temp variable to get the next node so we don't lose the linked list
            ListNode* temp = itr->next;
            // Now set the next to the previous node
            itr->next = prev;
            // Iterate both prev and temp
            prev = itr;
            itr = temp;
        }
        // when exited while loop we're done so return prev which should be the start of
        // the reversed list at this point
        return prev;
    }
};
