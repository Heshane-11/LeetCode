class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int node, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;
        for(int i = 0; i < adj[node].size(); i++){
            int x = adj[node][i];
            if(!vis[x]){
                dfs(isConnected, x, vis, adj);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);
        for(int i = 0; i < v; i++){
            for(int j = i + 1; j < v; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(v, false);
        int cnt = 0;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                dfs(isConnected, i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};