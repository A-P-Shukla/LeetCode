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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode* ath = list1;
        ListNode* bth = list1;
        ListNode* temp = list2;

        for(int i = 1; i < a; i++){
            ath = ath->next;
        }
        for(int i = 1; i <= b; i++){
            bth = bth->next;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }

        ath->next = list2;
        temp->next = bth->next;

        return dummy->next;
    }
};