class Solution {

public:

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if(arr[0]==0) dp[0][0]= 2;
    else dp[0][0]= 1;
    if (arr[0]!=0 && arr[0] <= k) {
        dp[0][arr[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= k; sum++) {
            int nontake = dp[ind - 1][sum];
            int take = 0;
            if (arr[ind] <= sum) {
                take = dp[ind - 1][sum - arr[ind]];
            }
            dp[ind][sum] = (take + nontake);
        }
    }

    return dp[n - 1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {
   int totalsum=0;
   for(int &it:arr){
      totalsum+=it;
   }
   if ((totalsum - d) < 0 || (totalsum - d) % 2 != 0) {
      return 0;
   }
   return findWays(arr, (totalsum - d) / 2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};