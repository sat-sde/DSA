class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n){
        if(i>=m || j>=n) return 0;
        if (obstacleGrid[i][j] == 1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=0;
        int right=0;
        if(i+1<m){
            down=solve(obstacleGrid,i+1,j,m,n);
        }
        if(j+1<n){
            right=solve(obstacleGrid,i,j+1,m,n);
        }
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(obstacleGrid,0,0,m,n);
    }
};