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
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> hashmap;
        Node *itr = head;
        while (itr)
        {
            hashmap[itr] = new Node(itr->val);
            itr = itr->next;
        }
        itr = head;
        while (itr)
        {
            hashmap[itr]->next = hashmap[itr->next];
            hashmap[itr]->random = hashmap[itr->random];
            itr = itr->next;
        }
        return hashmap[head];
    }
};
