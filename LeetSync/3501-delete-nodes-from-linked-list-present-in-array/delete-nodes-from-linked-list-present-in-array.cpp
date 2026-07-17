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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        ListNode* curr = head;

        unordered_set<int> s;
        for(auto num: nums){
            s.insert(num);
        }

        while(curr != nullptr){
            if(!s.count(curr->val)){
                dummy->next = curr;
                dummy = dummy->next;
            }
            curr = curr->next;
            dummy->next = nullptr;
        }
        
        return ans->next;
    }
};