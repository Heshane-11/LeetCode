class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size(), c = image[0].size();
        vector<vector<int>> res = image;

        int orig = image[sr][sc];
        if(orig == color) return res;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        res[sr][sc] = color;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            // up
            if(i > 0 && res[i-1][j] != color && image[i-1][j] == orig){
                q.push({i-1, j});
                res[i-1][j] = color;
            }
            // down
            if(i < r-1 && res[i+1][j] != color && image[i+1][j] == orig){
                q.push({i+1, j});
                res[i+1][j] = color;
            }
            // left
            if(j > 0 && res[i][j-1] != color && image[i][j-1] == orig){
                q.push({i, j-1});
                res[i][j-1] = color;
            }
            // right
            if(j < c-1 && res[i][j+1] != color && image[i][j+1] == orig){
                q.push({i, j+1});
                res[i][j+1] = color;
            }
        }
        return res;
    }
};