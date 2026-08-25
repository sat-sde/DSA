class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<=n+1;i++){
            int el=k*i;
            if(!st.count(el)) return el;
        }
        return 0;
    }
};