class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        vector<bool>vis(26,false);
        vector<int>lind(26);
        for(int i=0;i<n;i++){
            char ch=s[i];
            lind[ch-'a']=i;
        }
        string ans="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(vis[idx]==true){
                continue;
            }

            while(ans.length()>0 && ans.back()>ch && lind[ans.back() - 'a']>i){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }

            ans.push_back(ch);
            vis[ch-'a']=true;
        }
        return ans;
    }
};