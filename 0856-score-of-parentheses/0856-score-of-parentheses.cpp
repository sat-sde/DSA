class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int>st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }else {
                int x=st.top();
                st.pop();
                int sr=(x==0) ? 1:2*x;
                st.top()+=sr;
            }
        }
        return st.top();
    }
};