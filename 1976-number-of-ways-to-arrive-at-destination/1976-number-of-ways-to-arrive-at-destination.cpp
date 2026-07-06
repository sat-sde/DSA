class Solution {
public:
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
           long long cost = pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(cost > dist[node]) continue;
            for(auto &it:adj[node]){
                int ct=it.second;
                int adnode=it.first;

                if(cost + ct < dist[adnode]){
                    dist[adnode]=cost + ct;
                    ways[adnode]=ways[node];
                    pq.push({dist[adnode],adnode});
                }else if(cost + ct == dist[adnode]){
                    ways[adnode] = (ways[adnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};