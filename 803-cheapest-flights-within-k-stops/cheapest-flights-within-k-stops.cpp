class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        // {cost, node, stops}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        vector<int> stops(n, INT_MAX);

        while(!pq.empty()){
            auto [cost, node, st] = pq.top();
            pq.pop();

            // reached destination
            if(node == dst) return cost;

            // stop limit exceed or already visited with better stops
            if(st > k || st > stops[node]) continue;

            stops[node] = st;

            for(auto &it : adj[node]){
                int next = it.first;
                int price = it.second;

                pq.push({cost + price, next, st + 1});
            }
        }

        return -1;
    }
};