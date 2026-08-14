class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int i=0;
        int len=0;
        unordered_map<char,int>freq;
        for(int j=0;j<n;j++){
            freq[s[j]]++;
            while(freq[s[j]] > 2){
                freq[s[i]]--;
                i++;
            }
            int l = j-i+1;
            len=max(len,l);
        }
        return len;
    }
};