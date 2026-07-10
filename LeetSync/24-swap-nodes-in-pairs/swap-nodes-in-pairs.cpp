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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        if(!head -> next)
            return head;
        
        ListNode* list = swapPairs(head->next->next);

        ListNode* temp = head->next;
        temp->next = head;
        head->next = list;
        return temp;
    }
};