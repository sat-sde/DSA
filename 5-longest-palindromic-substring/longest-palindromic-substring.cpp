class Solution {
public:
    bool isValid(string &s,int i,int j){
        if(i>=j) return true;
        if(s[i]==s[j]){
            return isValid(s,i+1,j-1);
        }
       return false;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int ind=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isValid(s,i,j) && j-i+1 > maxi){
                    maxi=max(maxi,j-i+1);
                    ind=i;
                }
            }
        }
        return s.substr(ind,maxi);
    }
};