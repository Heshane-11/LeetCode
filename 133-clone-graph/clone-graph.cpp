/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* ans = new Node(node->val);
        mp[node] = ans;

        vector<bool> vis(101, false);

        queue<Node*> q;
        q.push(node);
        vis[node->val] = true;

        while(!q.empty()){
            Node* n = q.front();
            q.pop();

            for(auto neigh : n->neighbors){
                if(mp.find(neigh) == mp.end()){
                    mp[neigh] = new Node(neigh->val);
                }

                // add cloned neighbor
                mp[n]->neighbors.push_back(mp[neigh]);

                if(!vis[neigh->val]){
                    vis[neigh->val] = true;
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};