/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    
    void call(Node* a,vector<int> &v)
    {
        if(a)
        {
            v.push_back(a->val);
            for(int i=0;i<a->children.size();i++)
            {
                call(a->children[i],v);
            }
        }
        return ;
    }
    
public:
    vector<int> preorder(Node* a) {
        
        vector<int> v;
        call(a,v);
        return v;
        
    }
};