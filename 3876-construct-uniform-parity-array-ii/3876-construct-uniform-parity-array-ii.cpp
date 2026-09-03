class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int e=0,o=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                e++;
            }else{
                o++;
            }
            mn=min(mn,nums1[i]);
        }
        if(e==n || o==n) return true;
        if(mn%2==1) return true;
        if(o==0) return true;
        return false;
    }
};