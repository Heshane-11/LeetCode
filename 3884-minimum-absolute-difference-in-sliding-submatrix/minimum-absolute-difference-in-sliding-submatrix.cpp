class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        if(k == 1){
            return ans;
        }
        for(int i = 0; i <= m-k; i++){
            for(int j = 0; j <= n-k; j++){
                vector<int> v;
                for(int a = 0; a < k; a++){
                    for(int b = 0; b < k; b++){
                        v.push_back(grid[a+i][b+j]);
                    }
                }
                sort(v.begin(), v.end());
                int mini = INT_MAX;
                for(int a = 0; a < v.size()-1; a++){
                    if(v[a] != v[a+1]){
                        int x = abs(v[a]-v[a+1]);
                        mini = min(x, mini);
                    }
                    
                }
                if(mini == INT_MAX) mini = 0;
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};