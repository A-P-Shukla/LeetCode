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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        ListNode* current = head;
        while (current != nullptr) {
            arr.push_back(current->val);
            current = current->next;
        }
        for(int i = 0; i < arr.size(); i++){
            int sum = 0;
            for(int j = i; j < arr.size(); j++){
                sum += arr[j];
                if(sum == 0){
                    int shiftCount = j - i + 1;
                    for (int k = j + 1; k < arr.size(); ++k) {
                        arr[k - shiftCount] = arr[k];
                    }
                arr.resize(arr.size() - shiftCount);
                sum = 0;
                i = -1;
                break;
                }
            }
        }

        if(arr.size() == 0){
            return nullptr;
        }
        ListNode* head1 = new ListNode(arr[0]);
        ListNode* ans = head1;

        for(int i = 1; i < arr.size(); i++){
            ans->next = new ListNode(arr[i]);
            ans = ans->next;
        }

        return head1;
    }
};