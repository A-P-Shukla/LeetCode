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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        // 1. Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse the second half of the list
        ListNode *prev = nullptr, *curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // 3. Calculate max twin sum
        int maxTwinSum = 0;
        ListNode *firstHalf = head;
        ListNode *secondHalf = prev; // 'prev' is now the head of the reversed second half
        
        while (secondHalf) {
            maxTwinSum = std::max(maxTwinSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxTwinSum;
    }
};