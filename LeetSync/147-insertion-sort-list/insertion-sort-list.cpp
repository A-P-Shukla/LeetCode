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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        bool swapped;
        do {
            swapped = false;
            ListNode* current = head;
            while (current->next) {
                if (current->next->val < current->val) {
                    swap(current->val, current->next->val);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
        return head;
    }
};