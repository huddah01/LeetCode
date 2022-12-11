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
    ListNode* middleNode(ListNode* head) {
        // Initial idea: Two loops one while to increment and find size of linked list
        // The second for loop to get the middle node and return the middle node, we will use
        // Will use a counter var to hold the size and unchanging reference for the head which
        // We will later increment to the middle and return as our solution
        // Idea didn't use that much memory but the runtime was longer because for loop iterated
        // Through the linked list again
        /**
        // Initialize unchanging reference, iterator, and counter
        // even or odd
        ListNode* middle = head;
        ListNode* itr = head;
        int size = 0;
        bool even = false;
        
        // While loop to count size
        while(itr != nullptr) {
            itr = itr->next;
            size += 1;
        }
        // For loop to get middle
        for(int i = 0; i < (size / 2); i++) {
            middle = middle->next;
        }
        // Return middle
        return middle;
        */
        // Suggested idea: Using a slow pointer and a fast pointer, the slow pointer will increment by 1
        // And the fast pointer will increment by 2, by the time the fast pointer reaches the end the slow
        // Pointer must be in the middle because the fast pointer travels twice as fast
    
        // Initialize fast and slow pointer
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
    
        // While loop and traverse, we only care about fastPtr reaching the end
        // fastPtr is at the end when it is either nullptr(linked list is even length) 
        // Or it's next node is nullptr(linked list is odd length)
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        // Now slowPtr should be at middle
        return slowPtr;    
    }
};
