class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& candidates, int target, int i, vector<int>& v){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(v);
            }
            return;
        }
        if(target >= candidates[i]){
            v.push_back(candidates[i]);
            solve(ans, candidates, target-candidates[i], i, v);
            v.pop_back();
        }
        solve(ans, candidates, target, i+1, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, candidates, target, 0, v);
        return ans;
    }
};