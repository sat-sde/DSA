class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int r=1;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=l;
            l*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=r;
            r*=nums[i];
        }
        return ans;
    }
};