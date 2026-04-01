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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        unordered_map<ListNode*, bool> vis;
        ListNode* temp = head;
        vis[temp] = true;
        while(temp){
            if(temp->next && vis[temp->next]){
                return temp->next;
            }
            temp = temp->next;
            vis[temp] = true;
        }
        return NULL;
    }
};