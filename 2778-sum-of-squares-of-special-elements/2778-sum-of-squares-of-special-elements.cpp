class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        long long t=0;
        for(int i=0;i<n;i++){
            if(n % (i+1) == 0){
                t+= (long long)nums[i]*nums[i];
            }
        }
        return t;
    }
};