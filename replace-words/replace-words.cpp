class node{
    
    public :
    
    char val;
    unordered_map<char,node*> m;
    bool b;
    
    node(char v)
    {
        val = v;
        b = 0;
    }
    
};


class trie{
    
    node *root;
    
    public :
    
    trie()
    {
        root = new node('0');
    }
    
    void insert(string &a)
    {
        int n = a.size();
        node *p= root;
        for(int i=0;i<n;i++)
        {
            if(p->b==1)
                return ;
            if(p->m.count(a[i]))
            {
                p=p->m[a[i]];
            }
            else
            {
                node *t = new node(a[i]);
                p->m[a[i]]= t;
                p=p->m[a[i]];
            }
        }
        p->b = 1;
        return ;
    }
    
    string replace(string &a)
    {
        int n = a.size() , f =-1 ;
        node *p = root;
        for(int i=0;i<n;i++)
        {
            if(p->b==1)
            {
                f= i;
                break;
            }
            if(p->m.count(a[i]))
            {
                p=p->m[a[i]];
            }
            else
            {
                break;
            }
        }
        if(f==-1)
            return a;
        string ans = a.substr(0,f);
        return ans;
    }
    
    
};

class Solution {
public:
    string replaceWords(vector<string>& a, string s) {
        
        string ans;
        
        trie t;
        for(int i=0;i<a.size();i++)
            t.insert(a[i]);
        
        stringstream c(s);
        string h,k;
        
        while(getline(c,h,' '))
        {
            k = t.replace(h);
            ans += k;
            ans += " ";
        }
        ans.pop_back();
        return ans;
        
    }
};