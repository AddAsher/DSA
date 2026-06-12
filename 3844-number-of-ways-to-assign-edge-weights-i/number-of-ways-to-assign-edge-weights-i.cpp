class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxDepth=0;

    void dfs(vector<vector<int>>& adj, int node, int parent, int depth) {
            maxDepth = max(maxDepth, depth);
            for (int neighbor : adj[node]) {
                if (neighbor != parent) {  // avoid going back to parent
                    dfs(adj, neighbor, node, depth + 1);
                }
            }
        }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj, 1, -1, 0);


        long long result = 1;
        for (int i = 0; i < maxDepth - 1; i++) {
            result = (result * 2) % MOD;
        }
        return result;
    }    
};