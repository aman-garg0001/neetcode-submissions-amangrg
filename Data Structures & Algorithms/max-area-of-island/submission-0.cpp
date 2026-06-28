class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int islandArea = 0;
                    dfs(i, j, islandArea, grid, visited);
                    ans = max(ans, islandArea);
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, int &ans, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0 or visited[i][j]) {
            return;
        }

        visited[i][j] = 1;
        ans++;

        dfs(i+1, j, ans, grid, visited);
        dfs(i-1, j, ans, grid, visited);
        dfs(i, j+1, ans, grid, visited);
        dfs(i, j-1, ans, grid, visited);
    }
};