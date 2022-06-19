class node{
    
    public : 
    char c;
    vector<int> v;
    unordered_map<char,node*> m;
    node(char v)
    {
        c= v;
    }
    
};

class trie {
    
    node* root;
    public :
    
    trie()
    {
        root = new node('1');
    }
    
    void insert(string a,int k,vector<string> &v)
    {
        int n = a.size();
        int j;
        node *p = root;
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
            {
                p=p->m[a[i]];
                
            }
            else
            {
                node *y = new node(a[i]);
                p->m[a[i]] = y;
                p=p->m[a[i]];
            }
            j=0;
            vector<int> &h = p->v;
            while(j<h.size())
            {
                if(v[h[j]]>v[k])
                    break;
                j++;
            }
            h.insert(h.begin()+j,k);
            if(h.size()>3)
            h.pop_back();
        }
        return ;
    }
    
    vector<vector<int>> give(string a)
    {
        vector<vector<int>> ans;
        int n = a.size();
        node* p = root;
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
            {
                p=p->m[a[i]];
                ans.push_back(p->v);
            }
            else
                break;
        }
        return ans;
    }
    
    
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string a) {
        vector<vector<string>> ans;
        vector<string> b;
        vector<vector<int>> res;
        int n = v.size();
        trie tree;
        for(int i=0;i<n;i++)
        {
            tree.insert(v[i],i,v);
        }
        
        res = tree.give(a);
        for(int i=0;i<a.size();i++)
        {
            if(i<res.size()){
            for(int j=0;j<res[i].size();j++)
                b.push_back(v[res[i][j]]);
            }
            ans.push_back(b);
            b.clear();
        }
        
        return ans;
        
    }
};