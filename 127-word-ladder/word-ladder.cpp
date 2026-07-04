class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string w=q.front().first;
            int step=q.front().second;
            q.pop();
            if(w==endWord) return step;
            for(int i=0;i<w.length();i++){
                char original=w[i];
                for(char j='a';j<='z';j++){
                    w[i]=j;
                    if(st.find(w)!=st.end()){
                        st.erase(w);
                        q.push({w,step+1});
                    }
                }
                w[i]=original;
            }
        }
        return 0;
    }
};