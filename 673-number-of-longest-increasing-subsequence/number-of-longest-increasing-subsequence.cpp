class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1), cnt(n, 1);
        int maxLen = 1, result = 0;

        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[ind] > nums[prev]) {
                    if (dp[prev] + 1 > dp[ind]) {
                        dp[ind] = dp[prev] + 1;
                        cnt[ind] = cnt[prev];
                    } else if (dp[prev] + 1 == dp[ind]) {
                        cnt[ind] += cnt[prev]; // Add count
                    }
                }
            }
            maxLen = max(maxLen, dp[ind]);
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                result += cnt[i];
            }
        }

        return result;
    }
};