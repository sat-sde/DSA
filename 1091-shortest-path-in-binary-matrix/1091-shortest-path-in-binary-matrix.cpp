class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]!=0 || grid[m-1][n-1]!=0) return -1;
        if(grid[0][0]==0 && (m==1 && n==1)) return 1;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q;
        int dr[8]={-1,-1,-1,0,1,1,1,0};
        int dc[8]={-1,0,1,1,1,0,-1,-1};
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            for(int k=0;k<8;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==0){
                    if(dis+1<dist[nr][nc]){
                        dist[nr][nc]=dis+1;
                        if(nr==m-1 && nc==n-1) return dis+1;
                        q.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};