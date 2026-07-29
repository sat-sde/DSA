class Solution {
public:
    bool isPred(string a,string b){
        if(a.size()!=b.size()+1) return false;
        int i=0;
        int j=0;
        while(i<a.size()){
            if(j<b.size() && a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        vector<int>dp(n,1);
        int lis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPred(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                    lis=max(lis,dp[i]);
                }
            }
        }
        return lis;
    }
};