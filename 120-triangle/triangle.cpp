class Solution {
public:
    long long dp[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        memset(dp,0,sizeof(dp));
        for(int j=0;j<triangle[n-1].size();j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                 dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};