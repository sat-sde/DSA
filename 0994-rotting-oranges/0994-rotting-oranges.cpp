class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int t=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
    int tm=0;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();
        tm=max(t,tm);

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                q.push({{nr,nc},t+1});
                grid[nr][nc]=2;
            }
        }
    }

     for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=2 && grid[i][j]==1){
                   return -1;
                }
            }
        }
        return tm;
    }
};