class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string &s,string &t){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j]=solve(i-1,j-1,s,t);
        }else{
            int insert=1+solve(i,j-1,s,t);
            int del=1+solve(i-1,j,s,t);
            int repl=1+solve(i-1,j-1,s,t);
            dp[i][j]=min({insert,del,repl});
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,word1,word2);
    }
};