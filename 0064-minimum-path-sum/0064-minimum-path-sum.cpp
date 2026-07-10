class Solution {
public:
int dp[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int left=1e9;
                int up=1e9;
                if(i>0) left=dp[i-1][j];
                if(j>0) up=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(left,up);
            }
        }
        return dp[m-1][n-1];
    }
};