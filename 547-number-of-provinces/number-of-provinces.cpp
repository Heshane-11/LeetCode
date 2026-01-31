class Solution {
public:

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        int x = adj[node][i];
        if(!visited[x]){
            dfs(adj, visited, x);
        }
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);
        int cnt = 0;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(v, false);
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};