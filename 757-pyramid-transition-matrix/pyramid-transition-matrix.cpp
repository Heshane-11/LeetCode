class Solution {
public:
    unordered_map<string, bool> memo;

    bool help(string s, vector<string>& allowed, int i, string temp) {
        if (s.size() == 1) return true;

        if (i == 0 && memo.count(s)) return memo[s];

        if (i == s.size() - 1) {
            bool res = help(temp, allowed, 0, "");
            if (i == 0) memo[s] = res;
            return res;
        }

        for (int j = 0; j < allowed.size(); j++) {
            if (s[i] == allowed[j][0] && s[i + 1] == allowed[j][1]) {
                if (help(s, allowed, i + 1, temp + allowed[j][2])) {
                    if (i == 0) memo[s] = true;
                    return true;
                }
            }
        }

        if (i == 0) memo[s] = false;
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        return help(bottom, allowed, 0, "");
    }
};
