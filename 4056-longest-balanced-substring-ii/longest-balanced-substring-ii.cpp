class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        // 1️⃣ longest single-character substring
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) len++;
            else len = 1;
            ans = max(ans, len);
        }

        unordered_map<string, int> mp;

        int a = 0, b = 0, c = 0;

        // 2️⃣ three characters: a = b = c
        mp.clear();
        mp["0#0"] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            string key = to_string(b - a) + "#" + to_string(c - a);
            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        // 3️⃣ a = b (ignore c)
        mp.clear();
        mp["0#0"] = -1;
        a = b = c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            string key = to_string(a - b) + "#" + to_string(c);
            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        // 4️⃣ b = c (ignore a)
        mp.clear();
        mp["0#0"] = -1;
        a = b = c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            string key = to_string(b - c) + "#" + to_string(a);
            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        // 5️⃣ c = a (ignore b)
        mp.clear();
        mp["0#0"] = -1;
        a = b = c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            string key = to_string(c - a) + "#" + to_string(b);
            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }
};
