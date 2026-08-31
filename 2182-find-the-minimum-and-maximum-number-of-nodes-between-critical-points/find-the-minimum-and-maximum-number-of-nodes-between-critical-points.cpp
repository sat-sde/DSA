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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        vector<int>ind;
        int cnt=0;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            if(prev!=NULL && curr!=NULL){
                if((prev->val < temp->val && temp->val > curr->val) || (prev->val > temp->val && temp->val < curr->val)){
                    ind.push_back(cnt);
                }
            }
            cnt++;
            prev=temp;
            temp=curr;
        }
        int n=ind.size();
        if(n<2) return {-1,-1};
        int maxd = abs(ind[n-1]-ind[0]);
        int mind=INT_MAX;
        for(int i=1;i<n;i++){
            mind=min(mind,abs(ind[i]-ind[i-1]));
        }
        return {mind,maxd};
    }
};