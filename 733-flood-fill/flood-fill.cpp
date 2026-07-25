class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int org = image[sr][sc];
        if (org == color)
            return image;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vector<int> dirx = {0, 0, -1, 1};
        vector<int> diry = {1, -1, 0, 0};
        image[sr][sc] = color;
        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == org){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};