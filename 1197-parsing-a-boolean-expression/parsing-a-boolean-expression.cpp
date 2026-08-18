class Solution {
public:
    char solve(vector<char>&ans,char &op){
        if(op=='!'){
            if(ans[0]=='t') return 'f';
            return 't';
        }

        if(op=='|'){
            return any_of(begin(ans),end(ans),[](char ch){
                return ch=='t';
                }) ? 't' : 'f';
        }
        if(op=='&'){
            return any_of(begin(ans),end(ans),[](char ch){
                return ch=='f';
                }) ? 'f' : 't';
        }
        return 't';
    }

    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(expression[i]==',') continue;
            if(expression[i]==')'){
                vector<char>values;
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solve(values,op));
            }else{
                st.push(expression[i]);
            }
        }
        return st.top()=='t' ? true : false;
    }
};