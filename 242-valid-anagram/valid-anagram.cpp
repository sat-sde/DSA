class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp1;
        for(auto it:s){
            mpp1[it]++;
        }
        for(auto it:t){
            mpp1[it]--;
        }
        for(auto it:mpp1){
            if(it.second!=0) return false;
        }
        return true;
    }
};