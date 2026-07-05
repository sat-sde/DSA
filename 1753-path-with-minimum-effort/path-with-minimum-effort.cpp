class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==m-1 && c==n-1) return dis;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                 if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int neweffort=max(dis,abs(heights[nr][nc]-heights[r][c]));
                    if(neweffort < dist[nr][nc]){
                        dist[nr][nc]=neweffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                 }
            }
        }
        return -1;
    }
};