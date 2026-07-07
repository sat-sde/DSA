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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int component=0;
        int extedge=0;
        if(connections.size()<n-1) return -1;
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUpar(u)==ds.findUpar(v)){
                extedge++;
            }else{
                ds.UnionbyRank(u,v);
            }
        }
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i){
                component++;
            }
        }
       return (extedge >= component-1) ? component-1 : -1;
    }
};