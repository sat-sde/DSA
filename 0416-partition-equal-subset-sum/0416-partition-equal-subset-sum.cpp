class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int k=sum/2;
        vector<vector<int>> dp(n, vector<int>(k + 1, false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
             dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=k;t++){
                bool nontake = dp[i-1][t];
                bool take=false;
                if(nums[i]<=t){
                    take=dp[i-1][t-nums[i]];
                }
                dp[i][t] = (take || nontake);
            }
        }
        return dp[n-1][k];
    }
};