class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini=INT_MAX;
        int n=nums.size();
        for(int len=l;len<=r;len++){
            for(int i=0;i+len<=n;i++){
                int s=0;
                for(int j=i;j<i+len;j++){
                    s+=nums[j];
                }
                if(s > 0 && s < mini) mini=s;
            }
        }
        return mini==INT_MAX ? -1 : mini;
    }
};