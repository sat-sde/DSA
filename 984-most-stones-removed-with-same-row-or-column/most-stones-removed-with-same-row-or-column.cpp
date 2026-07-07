class Solution {
public:
    void dfs(vector<bool>&vis, vector<vector<int>>& stones, int ind) {
        int n = stones.size();
        vis[ind] = true;
        for (int i = 0; i < n; i++) {
            int r = stones[ind][0];
            int c = stones[ind][1];
            if (vis[i] == false && (stones[i][0] == r || stones[i][1] == c)) {
                dfs(vis, stones, i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int group = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i] == true) {
                continue;
            }
            dfs(vis,stones,i);
            group++;
        }
        return n - group;
    }
};