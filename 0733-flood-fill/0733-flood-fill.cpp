class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int orgColor = image[sr][sc];
        if (orgColor == color)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    image[nr][nc] == orgColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};