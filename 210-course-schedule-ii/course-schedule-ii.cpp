class Solution {
public:
bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, stack<int>& s, vector<bool>& df_vis){
    visited[node] = true;
    df_vis[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        int x = adj[node][i];
        if(!visited[x] && dfs(adj, visited, x, s, df_vis)){
            return true;
        }
        else if(df_vis[x]){
            return true;
        }
    }
    df_vis[node] = false;
    s.push(node);
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> df_vis(numCourses, false);
        stack<int> s;
        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && dfs(adj, visited, i, s, df_vis)){
                return {};
            }
        }
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};