class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return -1;
        if(grid[0][0] == 1) return -1;
        vector<pair<int,int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},           {0,1},
            {1,-1},  {1,0},   {1,1}
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        pq.push({1, {0,0}});
        grid[0][0] = 1;
        dist[0][0] = 1;
        while(!pq.empty()){
            auto [d, p] = pq.top();
            auto [x, y] = p;
            pq.pop();
            if(x == n-1 && y == n-1){
                return d;
            }
            for(int i = 0; i < directions.size(); i++){ 
                auto[dx, dy] = directions[i];
                int fx = x+dx; int fy = y+dy; 
                if(fx >= 0 && fx < n && fy >= 0 && fy < n && grid[fx][fy] == 0){
                    dist[fx][fy] = 1 + dist[x][y]; 
                    pq.push({dist[fx][fy], {fx,fy}}); 
                    grid[fx][fy] = 1; 
                } 
            }
        }
        return -1;
    }
};