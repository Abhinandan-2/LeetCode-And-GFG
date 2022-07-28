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
    vector<vector<int>> levelOrder(Node* a) {
        
        
        vector<vector<int>> ans;
        if(!a)
            return ans;
        vector<int> h;
        int i=1,k;
        
        queue<Node*> q;
        Node* p ;
        q.push(a);
        
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            h.push_back(p->val);
            k = p->children.size();
            for(int j=0;j<k;j++)
                q.push(p->children[j]);
            i--;
            if(i==0)
            {
                i= q.size();
                ans.push_back(h);
                h.clear();
            }
            
        }
            
        return ans;
        
        
    }
};











