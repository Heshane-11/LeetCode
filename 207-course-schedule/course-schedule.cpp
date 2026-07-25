class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& dfs_vis, int node){
        vis[node] = true;
        dfs_vis[node] = true;
        for(int i = 0; i < adj[node].size(); i++){
            int x = adj[node][i];
            if(!vis[x]){
                if(dfs(adj, vis, dfs_vis, x))
                    return true;
            }
            else if(dfs_vis[x]){
                return true;
            }
        }
        dfs_vis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> dfs_vis(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i] && dfs(adj, vis, dfs_vis, i)){
                return false;
            }
        }
        return true;
    }
};
