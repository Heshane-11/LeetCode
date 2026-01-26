class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mini = INT_MAX;
        for(int i = 0; i < arr.size()-1; i++){
            mini = min(mini, abs(arr[i]-arr[i+1]));
        }
        for(int i = 0; i < arr.size()-1; i++){
            if(abs(arr[i]-arr[i+1]) == mini){
                vector<int>v;
                v.push_back(arr[i]);
                v.push_back(arr[i+1]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};