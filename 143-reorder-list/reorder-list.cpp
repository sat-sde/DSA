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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode* temp = head;
        stack<ListNode*> st;
        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }
        int n = st.size();
        temp = head;
        for (int i = 0; i < n / 2; i++) {
            ListNode* last = st.top();
            st.pop();
            ListNode* curr = temp->next;
            temp->next = last;
            last->next = curr;
            temp = curr;
        }
        temp->next = NULL;
    }
};