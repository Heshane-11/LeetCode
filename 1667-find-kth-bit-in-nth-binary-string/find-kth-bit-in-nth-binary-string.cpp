class Solution {
public:
    string invert(string st){
        for(char &c : st){
            c ^= 1;
        }
        return st;
    }
    string find(int n){
        if(n == 1){
            return "0";
        }
        string prev = find(n - 1);
        string inv = invert(prev);
        reverse(inv.begin(), inv.end());
        return prev + "1" + inv;
    }
    char findKthBit(int n, int k) {
       string s = find(n);
        return s[k-1];
    }
};