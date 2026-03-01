class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int,int>> directions = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto [d, p] = pq.top();
            auto [x, y] = p;
            pq.pop();
            if (d > dist[x][y]) continue;
            if(x == m-1 && y == n-1){
                return d;
            }
            for(int i = 0; i < directions.size(); i++){ 
                auto[dx, dy] = directions[i];
                int fx = x+dx; int fy = y+dy; 
                if(fx >= 0 && fx < m && fy >= 0 && fy < n){
                    int eff = max(d, abs(heights[x][y]-heights[fx][fy]));
                    if (eff < dist[fx][fy]) {
                        dist[fx][fy] = eff;
                        pq.push({eff, {fx, fy}});
                    }
                } 
            }
        }
        return ans;
    }
};