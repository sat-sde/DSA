class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int recnt=t.length();
        if(recnt>m) return "";
        unordered_map<char,int>mpp;
        for(auto it:t){
            mpp[it]++;
        }
        int i=0,j=0;
        int start_i=0;
        int minwindowSize=INT_MAX;
        while(j<m){
            char ch=s[j];
            if(mpp[ch]>0){
                recnt--;
            }
            mpp[ch]--;
            while(recnt==0){
                int len=j-i+1;
                if(len<minwindowSize){
                    minwindowSize=len;
                    start_i=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                    recnt++;
                }
                i++;
            }
            j++;
        }
        return minwindowSize==INT_MAX ? "" : s.substr(start_i,minwindowSize);
    }
};