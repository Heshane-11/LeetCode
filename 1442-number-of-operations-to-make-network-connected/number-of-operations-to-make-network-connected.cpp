class Solution {
public:
    int find(int u, vector<int>& parent) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u], parent);
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = find(u, parent);
        v = find(v, parent);
        if (u == v) return;

        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[u] > rank[v]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& e : connections) {
            unite(e[0], e[1], parent, rank);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i)
                components++;
        }

        return components - 1;
    }
};
