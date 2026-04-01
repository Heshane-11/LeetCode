/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head){
            return false;
        }
        unordered_map<ListNode*, bool> vis;
        ListNode* temp = head;
        vis[temp] = true;
        while(temp){
            if(temp->next && vis[temp->next]){
                return true;
            }
            temp = temp->next;
            vis[temp] = true;
        }
        return false;
    }
};