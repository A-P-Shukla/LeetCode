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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* ans = curr;

        while(curr != nullptr && curr->next != nullptr){
            ListNode* temp = new ListNode(gcd(curr->val,  curr->next->val), curr->next);
            curr->next = temp;
            curr = temp->next;
        }
        return ans;
    }
};