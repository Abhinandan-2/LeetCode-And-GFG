class node {
    
    public :
    
    char val;
    vector<int> v;
    unordered_map<char,node*> m;
    node(char p){
        val = p;
    }
    
};


class trie
{
    node *root ;
    public :
    
    trie(){
        root = new node('/0');
    }
    
    void insert(string a,int k)
    {
        node *p= root;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
            {
                p= p->m[a[i]];
                p->v.push_back(k);
            }
            else
            {
                node *t = new node(a[i]);
                t->v.push_back(k);
                p->m[a[i]] = t;
                p=p->m[a[i]];
            }
        }
        return ;
    }
    
    vector<int> give(string a)
    {
        node *p = root;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(p->m.count(a[i]))
            {
                p=p->m[a[i]];
            }
            else
                return {};
        }
        return p->v;
    }
    
    
};

class WordFilter {
    
    trie forward , backward;
    
public:
    WordFilter(vector<string>& w) {
        
        int n = w.size();
        
        for(int i=0;i<n;i++)
        {
            forward.insert(w[i],i);
            reverse(w[i].begin(),w[i].end());
            backward.insert(w[i],i);
        }
        
        return ;
    }
    
    int f(string prefix, string suffix) {
        
        vector<int> a = forward.give(prefix);
        reverse(suffix.begin(),suffix.end());
        vector<int> b = backward.give(suffix);
        
        int n = a.size() , m = b.size();
        
        
        if(n>m)
            swap(a,b);
        
        n = a.size();
        m = b.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(binary_search(b.begin(),b.end(),a[i]))
                return a[i];
        }
        return -1;
        
//         int i=n-1 , j = m-1;
//         while(i>=0&&j>=0)
//         {
//             if(a[i]==b[j])
//                 return a[i];
//             if(a[i]>b[j])
//                 i--;
//             else
//                 j--;
//         }
        
//         return -1;
        
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */