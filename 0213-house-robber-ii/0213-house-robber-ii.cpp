class Solution {
public:
    int solve(vector<int>&nums){
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i-1>0){
                take+=prev2;
            }
            int nontake=prev;
            int curr=max(take,nontake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        return max(solve(nums1),solve(nums2));
    }
};