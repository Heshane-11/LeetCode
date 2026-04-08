// class Solution {
// public:
//     void floydWarshall(vector<vector<int>> &dist) {
//         int INF = 1e9;
//         int v = dist.size();
//         for(int x = 0; x < v; x++){
//             for(int i = 0; i < v; i++){
//                 for(int j = 0; j < v; j++){
//                     if(i == j){
//                         dist[i][j] = 0;
//                     }
//                     else if(dist[i][x] != INF && dist[x][j] != INF){
//                         dist[i][j] = min(dist[i][j] ,dist[i][x] + dist[x][j]);
//                     }
//                 }
//             }
//         }
//     }
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         int INF = 1e9;
//         vector<vector<int>> dist(n, vector<int>(n, INF));
//         for(int i = 0; i < edges.size(); i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int w = edges[i][2];
//             dist[u][v] = w;
//             dist[v][u] = w;
//         }
//         floydWarshall(dist);
//         int prev = INT_MAX;
//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             int cnt = 0;
//             for(int j = 0; j < n; j++){
//                 if(i != j && dist[i][j] != INF && dist[i][j] <= distanceThreshold){
//                     cnt++;
//                 }
//             }
//             if(cnt <= prev){
//                 prev = cnt;
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };


/*
🚀 Can we optimize?

👉 YES 🔥 — use Dijkstra's Algorithm from each node

⏱️ Complexity of Dijkstra approach

For one node:

O(E log V)

For all nodes:

O(n × E log V)

space: O(E)
*/
class Solution {
public:
    // Dijkstra function
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src}); // {distance, node}

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &it : adj[node]){
                int nxt = it.first;
                int wt = it.second;

                if(dist[nxt] > d + wt){
                    dist[nxt] = d + wt;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // build adjacency list once
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int ans = -1;
        int minReach = INT_MAX;

        for(int i = 0; i < n; i++){
            vector<int> dist = dijkstra(n, adj, i);

            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[j] <= distanceThreshold){
                    cnt++;
                }
            }

            // choose minimum, tie → larger index
            if(cnt <= minReach){
                minReach = cnt;
                ans = i;
            }
        }

        return ans;
    }
};

/*
⏱️ Complexity
🔹 Time:
O(n × E log V)
🔹 Space:
O(V + E)
*/
