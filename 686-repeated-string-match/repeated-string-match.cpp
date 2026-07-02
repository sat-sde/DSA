class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.length();
        int m=b.length();
        string s=a;
        int cnt=1;
        while(s.length()<m){
            s+=a;
            cnt++;
        }
        if(s.find(b)!=string::npos){
            return cnt;
        }
        s+=a;
        cnt++;
        if(s.find(b)!=string:: npos){
            return cnt;
        }
        return -1;
    }
};