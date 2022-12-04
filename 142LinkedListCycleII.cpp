/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Initial idea: Use a hash map to keep track of the nodes we have traversed
        // Once we find a duplicate node that means there is a cycle, if we reach nullptr
        // That means there was no duplicates and therefore no cycles
        
        // Declare hashmap and node iterator
        ListNode* itr = head;
        unordered_map<ListNode*, ListNode*> dupMap;
        
        // Traverse through the linked list and add to the map
        while(itr != nullptr) {
            // Check for duplicates
            if(dupMap.find(itr) != dupMap.end()) {
                // Duplicate found so return start of cycle
                return itr;
            }
            // No duplicate so we add it to the map
            else {
                // We map the current to its next node
                dupMap[itr] = itr->next;
            }
            // Increment the iterator
            itr = itr->next;
        }
        // If we exit the while loop then there is no cycle so return nullptr
        return nullptr;
    }
};
