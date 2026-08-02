class Solution {
public:
    int dp[501][501];
     int solve(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j) return nums[j];
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,piles)>=0;
    }
};