class Solution {
public:
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        memset(dp,0,sizeof(dp));
        int n=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n=s.length();
        return n-longestPalindromeSubseq(s);
    }
};