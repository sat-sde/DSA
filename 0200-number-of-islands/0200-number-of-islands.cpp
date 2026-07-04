class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==-1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){
                    bfs(grid,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};