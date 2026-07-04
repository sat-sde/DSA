class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && vis[nr][nc] == 0 &&
                grid[nr][nc] == 1) {
                dfs(nr, nc, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (!vis[i][j] && grid[i][j] == 1) {
                        dfs(i, j, grid, vis);
                    }
                }
            }
        }
            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (vis[i][j] == 0 && grid[i][j] == 1) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };