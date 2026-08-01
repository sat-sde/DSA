class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxarea=INT_MIN;
        while(i<=j){
            int l=min(height[i],height[j]);
            int b=j-i;
            int area=l*b;
            if(height[i]<=height[j]){
                i++;
            }else if(height[i]>height[j]){
                j--;
            }
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};