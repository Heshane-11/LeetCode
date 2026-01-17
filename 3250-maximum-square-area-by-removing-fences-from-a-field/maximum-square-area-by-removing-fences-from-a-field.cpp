class Solution {
    int mod = 1000000007;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        vector<int> h;
        vector<int> v;
        for(int i = 0; i < hFences.size(); i++){
            for(int j = i+1; j < hFences.size(); j++){
                h.push_back(abs(hFences[i]-hFences[j]));
            }
        }
        for(int i = 0; i < vFences.size(); i++){
            for(int j = i+1; j < vFences.size(); j++){
                v.push_back(abs(vFences[i]-vFences[j]));
            }
        }
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        long long maxi = -1;
        int i = 0;
        int j = 0;
        while(i < h.size() && j < v.size()){
            if(h[i] == v[j]){
                maxi = max(maxi, (long long)h[i]);
                j++;
                i++;
            }
            else if(h[i] < v[j]){
                i++;
            }
            else{
                j++;
            }
        }
        if(maxi == -1) return -1;

        return (1LL * maxi * maxi) % mod;
    }
};