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

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // A critical point requires at least 3 nodes in the list.
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;

        while (curr->next != nullptr) {
            bool isMaxima = (curr->val > prev->val) && (curr->val > curr->next->val);
            bool isMinima = (curr->val < prev->val) && (curr->val < curr->next->val);

            if (isMaxima || isMinima) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = std::min(minDistance, index - prevCritical);
                }
                prevCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // If less than two critical points were found
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = prevCritical - firstCritical;
        return {minDistance, maxDistance};
    }
};