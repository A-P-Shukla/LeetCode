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
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        ListNode* curr = head;

        while(curr != nullptr){
            int sum = 0;
            while(curr->val != 0){
                sum += curr->val;
                curr = curr->next;
            }

            if(sum != 0){
                ListNode* sumNode = new ListNode(sum);
                dummy->next = sumNode;
                dummy = dummy->next;
            }
            curr = curr->next;
        }
        return ans->next;
    }
};