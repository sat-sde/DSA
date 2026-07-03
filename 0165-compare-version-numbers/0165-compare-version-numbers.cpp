class Solution {
public:
vector<string>getToken(string s){
    vector<string>ans;
    stringstream ss(s);
    string token ="";
    while(getline(ss,token,'.')){
        ans.push_back(token);
    }
    return ans;
}
    int compareVersion(string version1, string version2) {
        vector<string>s1=getToken(version1);
        vector<string>s2=getToken(version2);
       int m=s1.size();
       int n=s2.size();
       int i=0;
       while(i<m || i<n){
        int a= (i<m) ? stoi(s1[i]) : 0;
        int b= (i<n) ? stoi(s2[i]) : 0;

        if(a>b) return 1;
        else if(b>a) return -1;
        else{
            i++;
        }
       }
       return 0;
    }
};