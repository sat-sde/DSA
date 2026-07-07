class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int getSize(int node) {
        return size[findUPar(node)];
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // Step 1: Connect all existing islands
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int node = row * n + col;
                        int adjNode = newr * n + newc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        // Step 2: Try converting each 0 into 1
        int mx = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int totalSize = 1;
                for (auto parent : components) {
                    totalSize += ds.getSize(parent);
                }

                mx = max(mx, totalSize);
            }
        }

        // Step 3: If grid is already all 1s
        for (int i = 0; i < n * n; i++) {
            mx = max(mx, ds.getSize(i));
        }

        return mx;
    }
};