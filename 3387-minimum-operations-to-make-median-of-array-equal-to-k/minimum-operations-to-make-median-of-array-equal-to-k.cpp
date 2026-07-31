class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        if(n%2==1 || n%2==0){
            int mid=n/2,exp=k;
            ans+=abs(nums[mid]-exp);
            for(int i=mid-1;i>=0;i--){
                if(nums[i]<=exp){
                    exp=min(exp,nums[i]);
                    continue;
                }
                ans+=(nums[i]-exp);
            }
            exp=k;
            for(int i=mid+1;i<n;i++){
                if(nums[i]>=exp){
                    exp=max(exp,nums[i]);
                    continue;
                }
                ans+=(exp-nums[i]);
            }
        }
        return ans;
    }
};