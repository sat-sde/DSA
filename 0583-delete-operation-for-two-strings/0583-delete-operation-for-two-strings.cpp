class Solution {
public:
    int dp[501][501];
    int lcs(string &s,string &t) {
        memset(dp,0,sizeof(dp));
        int n=s.length();
        int m=t.length();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int len=lcs(word1,word2);
        return (m+n)-(2*len);
    }
};