//                                leetcode 138                                   // SC=O(n)  TC=O(n)
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

        unordered_map<Node*,Node*> mapping;
        Node* original = head;
        Node* copyed = copyed_list;
        while(original != NULL){
            mapping[original] = copyed;
            original = original->next;
            copyed = copyed->next;
        }

        original = head;
        copyed = copyed_list;
        while(original != NULL){
            copyed->random = mapping[original->random];
            original = original->next;
            copyed = copyed->next;
        }

        return copyed_list;
    }
};