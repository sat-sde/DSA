class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int maxind=0;
        int minind=n;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxind=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minind=i;
            }
        }
        int left=min(minind,maxind);
        int right=max(minind,maxind);
        int op1= right+1;
        int op2=n-left;
        int op3= left+1+n-right;
        return min({op1,op2,op3});
    }
};