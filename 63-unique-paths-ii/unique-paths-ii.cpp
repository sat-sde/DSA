class Solution {
public:
    long long dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        if(obstacleGrid[0][0]==1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0) continue;
                int down=0;
                int right=0;
                if(i>0){
                    down=dp[i-1][j];
                }
                if(j>0){
                    right=dp[i][j-1];
                }
                dp[i][j]=down+right;
            }
        }
        return dp[m-1][n-1];
    }
};