class node{
    
    public :
    
    char c;
    unordered_map<char,node*> m;
    node(char v)
    {
        c = v;
    }
    
};

class trie{
    
    node* root;
    public :
    
    trie()
    {
        root= new node('1');
    }
    
    bool insert(string &a)
    {
        int n = a.size();
        node *p= root;
        bool ans = 1;
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
                p=p->m[a[i]];
            else
            {
                ans =0 ;
                node *t = new node(a[i]);
                p->m[a[i]] = t;
                p=p->m[a[i]];
            }
        }
        
        return ans;
    }
    
};

class Solution {
public:
    
    static bool com(string &a,string &b){
        return a.size()>b.size();
    }
    
    int minimumLengthEncoding(vector<string>& a) {
        
        sort(a.begin(),a.end(),com);
        int n = a.size(),ans=0;
        string h;
        trie tree;
        for(int i=0;i<n;i++)
        {
            h = a[i];
            reverse(h.begin(),h.end());
            if(!tree.insert(h))
                ans += (h.size()+1);
        }
        
        return ans;
        
        
        
    }
};