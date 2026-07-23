class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int i=0;
        int j=0;
        int cnt=0;
        while(j<n && i<m){
            if(s[i]>=g[j]){
                cnt++;
                j++;
                i++;
            }else{
                i++;
            }
        }
        return cnt;
    }
};