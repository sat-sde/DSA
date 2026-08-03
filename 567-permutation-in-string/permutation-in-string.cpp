class Solution {
public:
    bool checkInclusion(string s1, string s2) {
          int m=s1.length();
        int n=s2.length();
        if(m>n) return false;
        sort(s1.begin(),s1.end());
        for(int i=0;i<=n-m;i++){
            string temp=s2.substr(i,m);
            sort(temp.begin(),temp.end());
            if(temp==s1) return true;
        }
        return false;
    }
};