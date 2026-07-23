class Solution {
public:
int dp[13][10001];
    int solve(int i,int n,vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(i==n) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int nontake=solve(i+1,n,coins,amount);
        int take=INT_MAX;
        if(coins[i]<=amount){
            take=1+solve(i,n,coins,amount-coins[i]);
        }
        return dp[i][amount]=min(take,nontake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        int coin=solve(0,n,coins,amount);
        return coin >= 1e9 ? -1:coin;
    }
};