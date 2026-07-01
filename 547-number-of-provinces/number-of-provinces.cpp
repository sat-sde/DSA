class Solution {
public:
    void bfs(int node,vector<int>&vis, vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto it:adj[curr]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
       vector<vector<int>>adj(m);
       for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
       }
        vector<int>vis(m,0);
        int cnt=0;
        for(int i=0;i<m;i++){
            if(!vis[i]){
               bfs(i,vis,adj);
               cnt++;
            }
        }
        return cnt;
    }
};