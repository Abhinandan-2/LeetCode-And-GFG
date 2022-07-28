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
public:
    vector<int> preorder(Node* a) {
        
        
        stack<Node*> s;
        Node* p;
        int len;
        vector<int> ans;
        if(!a)
            return ans;
        s.push(a);
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            len = p->children.size();
            for(int i=len-1;i>=0;i--)
                s.push(p->children[i]);
        }
        
        return ans;
        
    }
};