class node{
    
    public:
    char val;
    unordered_map<char,node*> m;
    int index;
    node(char v)
    {
        val = v;
        index = -1;
    }
    
};


class trie{
    
    node *root;
    public :
    
    trie()
    {
        root = new node('0');
    }
    
    void insert(string &a,int in)
    {
        int n = a.size();
        node* p = root;
        if(n==0)
        {
            p->index = in;
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
                p=p->m[a[i]];
            else
            {
                node *t = new node(a[i]);
                p->m[a[i]] = t;
                p=p->m[a[i]] = t;
            }
        }
        
        p->index = in;
        return ;
        
    }
    
    vector<int> search(string &a)
    {
        int n = a.size(),f=0;
        node *p= root;
        vector<int> ans;
        if(p->index!=-1&&ispali(a,-1))
            ans.push_back(p->index);
        
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
                p=p->m[a[i]];
            else
            {
                f=1;
                break;
            }
            if(p->index!=-1&&ispali(a,i))
                ans.push_back(p->index);
        }
        if(f==1)
            return ans;
        string b;
        for(auto i:p->m)
            dfs(i.second,b,ans);
        
        return ans;
        
    }
    
    bool ispali(string &a,int s)
    {
        int n = a.size();
        for(int i=s+1,j=n-1;i<j;i++,j--)
            if(a[i]!=a[j])
                return 0;
        return 1;
    }
    
    void dfs(node* a,string &b,vector<int> &ans)
    {
        b.push_back(a->val);
        if(a->index!=-1&&ispali(b,-1))
            ans.push_back(a->index);
        for(auto i:a->m)
            dfs(i.second,b,ans);
        
        b.pop_back();
        return ;
            
    }
    
    
    
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& a) {
        
        trie t;
        vector<vector<int>> ans;
        vector<int> res;
        for(int i=0;i<a.size();i++)
        {
            reverse(a[i].begin(),a[i].end());
            t.insert(a[i],i);
            reverse(a[i].begin(),a[i].end());
        }
        
        for(int i=0;i<a.size();i++)
        {
            res = t.search(a[i]);
            for(int j=0;j<res.size();j++)
            {
                if(res[j]!=i)
                    ans.push_back({i,res[j]});
            }
        }
        return ans; 
        
    }
};