/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class box{
    public:
    int minNode;
    int maxNode;
    int sum;

    public:
    box(int sum,int minNode,int maxNode){
        this->sum=sum;
        this->minNode=minNode;
        this->maxNode=maxNode;
    }

};
class Solution {
public:

    box solve(TreeNode* root,int &maxsum){
        if(!root) return box(0,INT_MAX,INT_MIN);

        box left=solve(root->left,maxsum);
        box right=solve(root->right,maxsum);

        if(root->val > left.maxNode && root->val < right.minNode){
            int cursum=root->val+left.sum+right.sum;
            maxsum=max(maxsum,cursum);
            return box(cursum,min(left.minNode,root->val),max(root->val,right.maxNode));
        }
        return box(max(left.sum,right.sum),INT_MIN,INT_MAX);
    }
    int maxSumBST(TreeNode* root) {
       int maxsum=0;
       solve(root,maxsum);
       return maxsum;
    }
};