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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Initial idea: Compare each element and add to the linked list
        // whichever node is less; also handle edge cases of empty lists
        // Checked too many unnecessary cases, can just enter the while loop right away
        /**
        // First edge case: list 1 and list 2 are empty
        if(list1 == nullptr && list2 == nullptr) {
            // Return empty list
            return nullptr;
        }
        // Second edge case only list1 empty
        else if(list1 == nullptr) {
            // Return list2 by default
            return list2;
        }
        // Final edge case is list2 empty
        else if(list2 == nullptr) {
            return list2;
        }
        // General case where both lists are populated so we can compare
        // values and add to a linked list solution
        else {
            // Initialize linked list solution to return
            ListNode mergedList;
            // Compare values and add to the linked list solution
            While(list)
        }*/
        
        // Second Idea: Using a while loop, as long as list1 and list2 are not nullptr
        // we can compare values and add to a merge linked list
        // This idea was too complicated with initializing while also losing the reference
        // returning the end of the list as a solution
        // Initialize linked list solution to return
        /**
        ListNode* mergedList;
        // While both lists are still not empty
        while(list1 != nullptr && list2 != nullptr) {
            // Initialize merged list
            if(list1->val <= list2->val && mergedList == nullptr) {
                mergedList = new ListNode(list1->val);
                // Iterate the lists to continue comparing
                mergedList = mergedList->next;
                list1 = list1->next;
            }
            else if(list2->val < list1->val && mergedList == nullptr){
                mergedList = new ListNode(list2->val);
                // Iterate the lists
                mergedList = mergedList->next;
                list2 = list2->next;
            }
            // If merged list is already initialized
            else if(list1->val <= list2->val) {
                mergedList->next = new ListNode(list1->val);
                // Iterate the lists
                mergedList = mergedList->next;
                list1 = list1->next;
            }
            // When list2 val is less than list1 val
            else {
                mergedList->next = new ListNode(list2->val);
                // Iterate the lists
                mergedList = mergedList->next;
                list2 = list2->next;
            }
        }
        // If exited while loop then either list1 is nullptr or list 2 is nullptr
        // So we check both and finish the merged list
        if(list1 == nullptr) {
            mergedList->next = list2;
        }
        if(list2 == nullptr) {
            mergedList->next = list1;
        }
        // Return the merged list
        return mergedList;
        */
        // Suggested idea: Maintain unchanging reference to node for return then iterate
        // through the lists with a while loop, similar to second idea but done more simply
        // Initialize unchanging reference using -1 as an error value
        ListNode* mergedList = new  ListNode(-1);
        // Create an iterator for the while loop
        ListNode* mergedItr = mergedList;
        // While loop to compare values
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                mergedItr->next = list1;
                // Iterate the lists
                list1 = list1->next;
                mergedItr = mergedItr->next;
            }
            else {
                mergedItr->next = list2;
                // Iterate the lists
                list2 = list2->next;
                mergedItr = mergedItr->next;
            }
        }
        // When out of while loop then one of the lists are empty
        if(list1 == nullptr) {
            mergedItr->next = list2;
        }
        // list 2 must be empty
        else {
            mergedItr->next = list1;
        }
        // Return the next node of the unchanging reference for the solution
        return mergedList->next;
    }
};
