class Solution {
public:
    int dp[2001];
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int n,string &s){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=n;
        for(int len=i;len<n;len++){
            if(check(i,len,s)){
               int cut=1+solve(len+1,n,s);
               ans=min(ans,cut);
            }
        } 
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,s)-1;
    }
};