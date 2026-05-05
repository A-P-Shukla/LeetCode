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
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle empty list or single node
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Compute the length of the list and find the tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // 2. Calculate effective rotation
        k = k % n;
        if (k == 0) return head;

        // 3. Make the list circular
        tail->next = head;

        // 4. Find the new tail: it is at (n - k - 1) steps from the current head
        // Or (n - k) steps from the current tail
        int stepsToNewTail = n - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // 5. Break the circle and set the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};