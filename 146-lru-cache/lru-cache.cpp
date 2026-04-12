// class LRUCache {
//     vector<pair<int,int>> c;
//     int x;
// public:
//     LRUCache(int capacity) {
//         x = capacity;
//     }
    
//     int get(int key) {
//         for(int i = 0; i < c.size(); i++){
//             auto[k, v] = c[i];
//             if(k == key){
//                 c.erase(c.begin() + i);
//                 c.push_back({k, v});
//                 return v;
//             }
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         bool found = false;
//         for(int i = 0; i < c.size(); i++){
//             auto [k, v] = c[i];
//             if(k == key){
//                 c.erase(c.begin() + i);
//                 c.push_back({key, value});
//                 found = true;
//                 break;
//             }
//         }
//         if(!found){
//             c.push_back({key, value});
//         }
//         if(c.size() > x){
//             c.erase(c.begin());
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


/*
🚀 Approach (LRU Cache)

👉 Use 2 data structures:

Doubly Linked List (DLL)
Front → Most Recently Used (MRU)
Back → Least Recently Used (LRU)
HashMap (unordered_map)
key → {iterator in DLL, value}
Gives O(1) access
⚙️ Algorithm

🔹 get(key)
If key not in map → return -1
Else:
Move key to front (MRU)
Return value

🔹 put(key, value)
If key exists:
Update value
Move to front
Else:
If capacity full:
Remove LRU (back of DLL)
Delete from map
Insert new key at front
Store iterator in map

⏱️ Complexity
Time:
get → O(1)
put → O(1)
Space:
*/

 class LRUCache {
public:
    list<int> dll;  // stores keys
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        makeRecentlyUsed(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;     // update value
            makeRecentlyUsed(key);      // move to front
        }
        else{
            if(dll.size() == n){
                int last = dll.back();  // LRU
                dll.pop_back();
                mp.erase(last);
            }

            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
    }
};