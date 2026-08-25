class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>mpp(26,0);
        int start=0;
        int end=0;
        for(int i=0;i<n;i++){
            mpp[s[i]-'a']=i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            end=max(end,mpp[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};