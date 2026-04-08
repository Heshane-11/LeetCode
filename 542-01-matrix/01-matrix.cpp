/*
❌ 1. Brute Force (Worst)
💡 Idea

👉 Har 1 ke liye:

BFS chalao
nearest 0 dhoondo
⚡ Steps

For every cell:

agar 1 hai → BFS start
jab tak 0 na mile → explore
⏱️ Complexity
Cells = m × n

Har cell se BFS → O(mn)

Total = O((mn)²) ❌
*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));

        // Step 1: push all 0s into queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Step 2: BFS
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};