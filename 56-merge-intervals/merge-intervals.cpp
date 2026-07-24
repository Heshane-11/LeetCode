class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= curr[1]){
                vector<int> v(2);
                v[0] = curr[0];
                v[1] = max(curr[1], intervals[i][1]);
                curr = v;
            }
            else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};