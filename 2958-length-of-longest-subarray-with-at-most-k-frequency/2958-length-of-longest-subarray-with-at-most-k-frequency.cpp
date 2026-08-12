class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int ans=0;
        int start=-1;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                start++;
                freq[nums[start]]--;
            }
            ans=max(ans,i - start);
        }
        return ans;
    }
};