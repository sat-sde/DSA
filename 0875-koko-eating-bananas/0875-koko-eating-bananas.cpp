class Solution {
public:
    bool isValid(vector<int>& piles, int h,int k){
        long long hrs=0;
        for(int i=0;i<piles.size();i++){
           hrs += ceil((double)piles[i] / k);
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int high=*max_element(piles.begin(),piles.end());
        while(l<=high){
            int m=l+(high-l)/2;
            if(isValid(piles,h,m)==true){
                high=m-1;
            }else {
                l=m+1;
            }
        }
        return l;
    }
};
