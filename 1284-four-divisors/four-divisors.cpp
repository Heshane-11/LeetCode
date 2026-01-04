class Solution {
public:

    vector<int> div(int n, int &cnt){
        vector<int> v;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                v.push_back(i);
                ++cnt;
                if(n/i != i){
                    v.push_back(n/i);
                    cnt++;
                }
            }
        }
        return v;
    }

    int sumFourDivisors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < 6){
                continue;
            }
            else{
                cnt = 0;
                vector<int> v = div(nums[i], cnt);
                if(cnt == 4){
                    for(auto j : v){
                        sum += j;
                    }
                }
            }
        }
        return sum;
    }
};