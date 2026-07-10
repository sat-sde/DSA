class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        memset(dp,0,sizeof(dp));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int down=0;
                int right=0;
                if(i+1<m){
                    down=dp[i+1][j];
                }
                 if(j+1<n){
                    right=dp[i][j+1];
                }
                dp[i][j]=down+right;
            }
        }
        return dp[0][0];
    }
};