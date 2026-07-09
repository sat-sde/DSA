class Solution {
public:
    int solve(int i,vector<int>&dp,vector<int>&nums){
        if(i == 0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int nontake=solve(i-1,dp,nums);
        int take=INT_MIN;
        if(i-1>=0){
            take=nums[i]+solve(i-2,dp,nums);
        }
        return dp[i]=max(take,nontake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);
    }
};