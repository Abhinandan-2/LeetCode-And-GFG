class node{
    public :
    string val;
    unordered_map<string,node*> m;
    bool b;
    node(string v)
    {
        val = v;
        b = false;
    }
};

class trie{
    
    node *root;
    
    public:
    
    trie()
    {
        root = new node("0");
    }
    
    bool insert(string &a)
    {
        node *p = root;
        int i =1 , n = a.size(),f=1;
        string h ;
        while(i<n)
        {
            if(a[i]=='/')
            {
                h = a.substr(f,i-f);
                f = i+1;
                if(p->m.count(h))
                    p=p->m[h];
                else
                {
                    node *t= new node(h);
                    p->m[h] = t;
                    p=p->m[h];
                }
            }
            if(p->b)
                return false;
            i++;
        }
        h = a.substr(f,n-f);
        if(p->m.count(h))
            p=p->m[h];
        else
        {
            
            node *t= new node(h);
            p->m[h] = t;
            p=p->m[h];
        }
        if(p->b)
            return false;
        p->b = true;
        return true;
    }
    
    
};


class Solution {
public:
    
    static bool com(string &a,string &b)
    {
        int h= 0 , k = 0;
        for(auto i:a)
            if(i=='/')
                h++;
        for(auto i:b)
            if(i=='/')
                k++;
        
        return h<k;
        
    }
    
    vector<string> removeSubfolders(vector<string>& a) {
        
        int n = a.size(),size;
        
        sort(a.begin(),a.end(),com);
        
        vector<string> ans;
        trie Tree;
        for(int i=0;i<n;i++)
        {
            size = a[i].size();
            if(a[i][size-1]!='/')
            {
                if(Tree.insert(a[i]))
                    ans.push_back(a[i]);
            }
            // cout<<i<<" ";
        }
        
        
        return ans;
        
    }
};