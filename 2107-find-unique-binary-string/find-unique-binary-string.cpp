class Solution {
public:

    int dec(string s){
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int d = s[i] - '0';
            ans += d * pow(2, n-i-1);
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> v;
        int n = nums[0].size();
        for(int i = 0; i < nums.size(); i++){
            v.push_back(dec(nums[i]));
        }
        sort(v.begin(), v.end());
        int ans = v.size();
        for(int i = 0; i < v.size(); i++){
            if(v[i] != i){
                ans = i;
                break;
            }
        }
        string a = "";
        if(ans == 0) a = "0";
        while(ans != 0){
            int d = ans % 2;
            char c = d + '0';
            a += c;
            ans /= 2;
        }
        reverse(a.begin(), a.end());
        while(a.size() < n){ // changed (ensure length n)
            a = "0" + a;
        }

        return a;
    }
};