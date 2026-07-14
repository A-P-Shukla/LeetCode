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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> output(k, nullptr);
        ListNode* temp = head;
        ListNode* curr = head;

        int size = 0;

        while(temp != nullptr){
            size++;
            temp = temp->next;
        }

        int baseSize = size/k;
        int extra = size%k;

        for(int i = 0; i < k; i++){
            if(!curr){
                output[i] = nullptr;
                continue;
            }

            output[i] = curr;

            int partSize = baseSize + (i < extra ? 1 : 0);

            for(int j = 1; j < partSize; j++){
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return output;
    }
};