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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* current = head;
        while(current != nullptr){
            arr.push_back(current->val);
            current = current->next;
        }
        int n = arr.size();
        int temp = arr[k - 1];
        arr[k-1] = arr[n - k];
        arr[n - k] = temp;

        ListNode* ans = new ListNode(arr[0]);
        ListNode* temp1 = ans;

        for(int i = 1; i < n; i++){
            temp1->next = new ListNode(arr[i]);
            temp1 = temp1->next;
        }
        return ans;
    }
};