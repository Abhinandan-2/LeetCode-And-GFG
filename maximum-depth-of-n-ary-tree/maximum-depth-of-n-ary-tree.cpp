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
    int maxDepth(Node* a) {
        
        if(!a)
            return 0;
        
        int ans =0 ,res;
        
        for(int i=0;i<a->children.size();i++)
        {
            res = maxDepth(a->children[i]);
            ans = max(ans,res);
        }
        return ans+1;
        
    }
};