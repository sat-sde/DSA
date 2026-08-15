class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int txor=0;
        bool allzeros=true;
        for(auto it:nums){
            txor^=it;
            if(it>0){
                allzeros=false;
            }
        }
        if(txor>0) return n;
        return allzeros==true ? 0:n-1; 
    }
};