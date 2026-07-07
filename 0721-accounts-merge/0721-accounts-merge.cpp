class DisjointSet{
    vector<int>rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }

    void UnionbyRank(int u,int v){
        int ul_p=findUpar(u);
        int vl_p=findUpar(v);
        if(ul_p==vl_p) return;
        if(rank[ul_p]<rank[vl_p]){
            parent[ul_p]=vl_p;
        }else if(rank[vl_p]<rank[ul_p]){
             parent[vl_p]=ul_p;
        }else{
             parent[ul_p]=vl_p;
             rank[vl_p]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                }else{
                    ds.UnionbyRank(i,mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto &it:mapMailNode){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};