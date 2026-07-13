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
        stack<int> st;

        ListNode* curr = head;

        while(curr != nullptr){
            st.push(curr->val);
            curr = curr->next;
        }
        int ans = 0, count = 1;
        int n = st.size();
        ListNode* temp = head;
        
        while(count <= n/2){
            ans = max(ans, temp->val + st.top());
            st.pop();
            temp = temp->next;
            count++;
        }

        return ans;
    }
};