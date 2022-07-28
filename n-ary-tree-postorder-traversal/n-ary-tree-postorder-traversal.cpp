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
    vector<int> postorder(Node* a) {
        
        vector<int> ans;
        if(!a)
            return ans;
        stack<pair<Node*,int>> s;
        pair<Node*,int> p;
        int len ,h ;
        s.push({a,0});
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            if(p.second==1)
            {
                ans.push_back(p.first->val);
                continue;
            }
            s.push({p.first,1});
            len = p.first->children.size();
            for(int i=len-1;i>=0;i--)
            {
                s.push({p.first->children[i],0});
            }
        }
        return ans;
        
    }
};