class Solution {
public:
    int dp[1001];
    int solve(int i,vector<int>&cost){
        if(i==0) return cost[0];
        if(i==1) return cost[1];
        if(dp[i]!=-1) return dp[i];
        int take1=cost[i]+solve(i-1,cost);
        int take2=cost[i]+solve(i-2,cost);
        return dp[i]=min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(n-1,cost),solve(n-2,cost));
    }
};