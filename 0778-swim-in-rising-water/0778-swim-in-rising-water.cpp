class Solution {
public:
    bool dfs(int mid, vector<vector<int>>& grid, int n, int i, int j, vector<vector<int>>& vis) {
        if (i == n - 1 && j == n - 1) {
            return true;
        }
        vis[i][j] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            int nr = i + dr[d];
            int nc = j + dc[d];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && vis[nr][nc] == 0 && grid[nr][nc] <= mid) {
                if (dfs(mid, grid, n, nr, nc, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int low = 0;
        int high = (m * n) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<vector<int>> vis(m, vector<int>(n, 0));
            if (grid[0][0] <= mid && dfs(mid, grid, n, 0, 0, vis) == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};