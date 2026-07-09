class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==1) return nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int nontake=dp[i-1];
            int take=nums[i];
            if(i-1>0){
                take+=dp[i-2];
            }
            dp[i]=max(take,nontake);
        }
        return dp[n-1];
    }
};