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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    ds.UnionbyRank(i,j);
                }
            }
        }
        int grp=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i){
                grp++;
            }
        }
        return n-grp;
    }
};