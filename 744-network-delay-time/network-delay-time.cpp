class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>parent(n+1, -1);
        vector<int>dist(n+1, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});
        parent[k] = k;
        while(!pq.empty()){
            int x = pq.top().second;
            int x_dis = pq.top().first;
            pq.pop();
            
            if (x_dis > dist[x]) continue;
            
            for(int i = 0; i < adj[x].size(); i++){
                int node = adj[x][i].first;
                int w = adj[x][i].second;
                if(w + x_dis < dist[node]){
                    dist[node] = w + x_dis;
                    parent[node] = x;
                    pq.push({dist[node], node});
                }
            }
        }
        int mini = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            mini = max(mini, dist[i]);
        }
        return mini;
    }
};