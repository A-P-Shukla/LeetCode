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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(-1);
        ListNode* ans = &dummy;
        ListNode* curr = head->next;

        while(curr != nullptr){
            int sum = 0;
            while(curr->val != 0){
                sum += curr->val;
                curr = curr->next;
            }

            ListNode* sumNode = new ListNode(sum);
            ans->next = sumNode;
            ans = ans->next;
            
            curr = curr->next;
        }
        return dummy.next;
    }
};