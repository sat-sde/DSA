class Solution {
public:
    long long dp[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, 0, sizeof(dp));
        for (int t = 0; t <= amount; t++) {
            if(t%coins[0]==0)  dp[0][t] = t/coins[0];
            else dp[0][t]=1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int nontake = dp[i-1][t];
                int take = 1e9;
                if (coins[i] <= t) {
                    take = 1 + dp[i][t - coins[i]];
                }
                dp[i][t] = min(take, nontake);
            }
        }
        int coin = dp[n-1][amount];
        return coin >= 1e9 ? -1 : coin;
    }
};