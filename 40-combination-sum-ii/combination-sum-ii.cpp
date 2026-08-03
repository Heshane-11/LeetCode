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
            solve(ans, candidates, target-candidates[i], i+1, v);
            v.pop_back(); //pop_back() isliye lagate hain taaki recursive call ke baad vector ko uski previous state me restore (undo) kiya ja sake, warna next recursion galat elements ke saath chalegi.

        }
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]){
            i++;
        }
        solve(ans, candidates, target, i+1, v);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, candidates, target, 0, v);
        return ans;
    }
};