class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool ans = true;
        vector<bool> isVisited(n, false);
        dfs(0, -1, ans, adj, isVisited);
        for (int i = 0; i < n; i++) {
            if (isVisited[i] == false) {
                return false;
            }
        }
        return ans;
    }

    void dfs(int node, int parent, bool &ans,
     vector<vector<int>> &adj, vector<bool> &isVisited) {
        isVisited[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            if (adj[node][i] == parent) {
                continue;
            } else {
                if (isVisited[adj[node][i]]) {
                    ans = false;
                    return;
                }
                dfs(adj[node][i], node, ans, adj, isVisited);
            }
        }
    }
};
