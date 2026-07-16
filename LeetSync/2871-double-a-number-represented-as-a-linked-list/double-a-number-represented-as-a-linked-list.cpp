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

    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseLL(head);
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int carry = 0;

        while(curr !=  nullptr){
            int newValue = curr->val * 2 + carry;
            curr->val = newValue % 10;

            if(newValue >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            prev = curr;
            curr = curr->next;

        }
        if(carry != 0){
                ListNode* newHead = new ListNode(carry);
                prev->next = newHead;
        }
        return reverseLL(head);
    }
};