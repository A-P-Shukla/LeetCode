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
        if(!head || !head->next){
            return head;;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }

        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        int midi = count/2;
        ListNode* mid = head;
        while(midi--){
            mid = mid->next;
        }
        ListNode* rev = reverseLL(mid);
        ListNode* temp1 = head;

        while(rev != nullptr){
            if(rev->val != temp1->val)
                return false;
            
            rev = rev->next;
            temp1 = temp1->next;
        }
        return true;
    }
};