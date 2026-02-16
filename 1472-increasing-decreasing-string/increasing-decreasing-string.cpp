class Solution {
public:
    string sortString(string s) {
        sort(s.begin(), s.end());   // 🔧 UPDATE 1: sort ascending

        string res;
        bool inc = true;            // true = increasing, false = decreasing

        while (!s.empty()) {
            if (inc) {
                // pick smallest, then next greater
                char last = 0;
                for (int i = 0; i < s.size(); ) {
                    if (res.empty() || s[i] > last) {
                        res.push_back(s[i]);
                        last = s[i];
                        s.erase(i, 1);   // erase chosen char
                    } else {
                        i++;
                    }
                }
            } else {
                // pick largest, then next smaller
                char last = 127;
                for (int i = s.size() - 1; i >= 0; ) {
                    if (s[i] < last) {
                        res.push_back(s[i]);
                        last = s[i];
                        s.erase(i, 1);
                        i = min(i, (int)s.size() - 1);
                    } else {
                        i--;
                    }
                }
            }
            inc = !inc;  // 🔧 UPDATE 6: flip direction only after full pass
        }
        return res;
    }
};
