//                                leetcode 138                                   //SC = O(n)     TC = O(n2)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    Node* copyWithoutRandom(Node* head) {
        Node* new_head = new Node(head->val);
        Node* tail = new_head;
        head = head->next;
        while(head!=NULL) {
            Node* new_node = new Node(head->val);
            tail->next = new_node;
            tail = tail->next;
            head = head->next;
        }
        return new_head;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) { return head; }
        Node* copyed_list = copyWithoutRandom(head);

        Node* temp1 = head;
        Node* temp2 = copyed_list;
        while(temp1!=NULL) {
            Node* temp1_random = temp1->random;
            if(temp1_random == NULL) { temp2->random=NULL; }
            else if(temp1_random == head) { temp2->random=copyed_list; }
            else if(temp1_random == temp1) { temp2->random=temp2; }
            else{
                Node* temp11 = head;
                Node* temp22 = copyed_list;
                while(temp1_random != temp11) {
                    temp11 = temp11->next;
                    temp22 = temp22->next;
                }
                temp2->random = temp22;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return copyed_list;
    }
};