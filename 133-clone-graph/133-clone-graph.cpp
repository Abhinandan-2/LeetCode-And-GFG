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
    
    void call(Node* a,unordered_map<int,Node*> &m)
    {
        int h = a->neighbors.size(),temp;
        Node *cur = m[a->val];
        for(int i=0;i<h;i++)
        {
            temp = a->neighbors[i]->val;
            if(!m.count(temp))
            {
                Node *t = new Node(temp);
                cur->neighbors.push_back(t);
                m[temp] = t;
                call(a->neighbors[i],m);
            }
            else
            {
                cur->neighbors.push_back(m[temp]);
            }
        }
        return ;
    }
    
    
    Node* cloneGraph(Node* a) {
        
        if(!a)
        return a;
        unordered_map<int,Node*> m;
        Node *ans = new Node(a->val);
        m[a->val] = ans;
        call(a,m);
        
        return ans;
    }
};