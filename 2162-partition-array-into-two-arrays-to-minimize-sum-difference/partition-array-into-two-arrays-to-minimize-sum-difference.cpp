class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    bits++;
                }
            }
            left[bits].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[n + i];
                    bits++;
                }
            }
            right[bits].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int l = 0; l <= n; l++) {
            int r = n - l;

            for (int x : left[l]) {
                int target = total / 2 - x;

                auto it = lower_bound(right[r].begin(), right[r].end(), target);

                if (it != right[r].end()) {
                    int s = x + *it;
                    ans = min(ans, abs(total - 2 * s));
                }

                if (it != right[r].begin()) {
                    --it;
                    int s = x + *it;
                    ans = min(ans, abs(total - 2 * s));
                }
            }
        }

        return ans;
    }
};