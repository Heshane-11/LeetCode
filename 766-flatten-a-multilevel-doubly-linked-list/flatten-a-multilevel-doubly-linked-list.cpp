/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* flatten(Node* head) {
        if(!head){
            return NULL;
        }
        Node* temp = head;
        Node* forw = temp;
        Node* forw1 = temp;
        bool x = false;
        while(temp){
            if(temp->child){
                if(temp->next){
                    forw = temp->next;
                    forw ->prev = NULL;
                    x = true;
                }
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
                if(x){
                    forw1 = temp;
                    while(forw1->next){
                        forw1 = forw1->next;
                    }
                    forw1->next = forw;
                    forw->prev = forw1;
                    }
            }
            temp = temp->next;
        }
        return head;
    }
};