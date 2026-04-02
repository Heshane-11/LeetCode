class Solution {
public:
    Node* dfs(Node* head){
        Node* curr = head;
        Node* last = NULL;

        while(curr){
            Node* nextNode = curr->next;

            // if no child
            if(!curr->child){
                last = curr;
            }
            else{
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                // connect curr with child
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // connect child tail with next
                if(nextNode){
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
            }

            curr = nextNode;
        }
        return last;
    }

    Node* flatten(Node* head) {
        if(!head) return NULL;
        dfs(head);
        return head;
    }
};