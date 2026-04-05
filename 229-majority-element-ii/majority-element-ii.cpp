class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 1; // different initial values

        for(int x : nums){
            if(x == ele1) cnt1++;
            else if(x == ele2) cnt2++;
            else if(cnt1 == 0){
                ele1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = x;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        // verification step
        cnt1 = 0, cnt2 = 0;
        for(int x : nums){
            if(x == ele1) cnt1++;
            else if(x == ele2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size();

        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3) ans.push_back(ele2);

        return ans;
    }
};

/*


🏆 Optimal Approach → Boyer-Moore (Extended)

👉 Maintain:

2 candidates
2 counts
⚡ Idea

Har element ke liye:

Same as candidate → count++
Agar count 0 → new candidate
Agar dono different → count--

🔑 Important Points
✅ Why 2 candidates?
> n/3 → max 2 elements possible
⚠️ Why verification needed?

👉 Unlike n/2 case:

Yahan guarantee nahi hai ki element exist karega
🧠 Intuition (simple)

“We cancel out groups of 3 different elements — jo bachega wahi majority hoga.”

📊 Complexity
Time: O(n)
Space: O(1) 🔥


*/