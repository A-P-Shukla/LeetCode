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
    ListNode* deleteMiddle(ListNode* head) {
        // If the list has only one node, deleting the middle results in an empty list.
        if (!head || !head->next) {
            return nullptr;
        }

        // Use a dummy node or initialize pointers to track the node before the middle.
        // fast moves twice as fast as slow.
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'prev' is now pointing to the node before the middle node 'slow'.
        // Skip the middle node.
        prev->next = slow->next;
        
        return head;
    }
};