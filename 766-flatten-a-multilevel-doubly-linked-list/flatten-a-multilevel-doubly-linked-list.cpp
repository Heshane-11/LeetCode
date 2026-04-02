class Solution {
public:
    
    Node* solve(Node* temp){
        Node* forw1 = temp;   // tail tracker

        while(temp){
            Node* forw = temp->next;

            if(temp->child){
                Node* childHead = temp->child;
                Node* childTail = solve(childHead);

                // connect temp with child
                temp->next = childHead;
                childHead->prev = temp;
                temp->child = NULL;

                // connect child tail with next
                if(forw){
                    childTail->next = forw;
                    forw->prev = childTail;
                }

                forw1 = childTail; // update tail
            }
            else{
                forw1 = temp;
            }

            temp = forw;
        }
        return forw1; // return tail
    }

    Node* flatten(Node* head) {
        if(!head) return NULL;
        solve(head);
        return head;
    }
};