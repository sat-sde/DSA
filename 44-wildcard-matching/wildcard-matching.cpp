class Solution {
public:
    int dp[2001][2001];
    bool solve(int i,int j,string &s,string &p){
        if(i<0 && j<0) return true;
        if(i<0 && j>0) return false;
        if (j < 0){
            for (int k = 0; k <= i; k++) {
                 if (s[k] != '*')
                    return false;
            }
    return true;
}
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || s[i]=='?'){
            return dp[i][j]=solve(i-1,j-1,s,p);
        }else if(s[i]=='*'){
            return dp[i][j]=solve(i-1,j,s,p) || solve(i,j-1,s,p);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        memset(dp,-1,sizeof(dp));
        return solve(n-1, m-1, p, s);
    }
};