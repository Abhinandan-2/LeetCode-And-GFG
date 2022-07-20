class node{
    
    
    public :
    
    char val ;
    unordered_map<char,node*> m;
    bool end ;
    
    node(char v)
    {
        val = v;
        end =0;
    }
    
};


class Trie {
    
    node *root;
    
public:
    Trie() {
        
        root = new node('\0');
        
    }
    
    void insert(string word) {
        
        node *p= root;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(p->m.count(word[i]))
            {
                p=p->m[word[i]];
            }
            else
            {
                node *t = new node(word[i]);
                p->m[word[i]] = t;
                p=p->m[word[i]];
            }
        }
        p->end = 1;
        return ;
        
    }
    
    bool search(string word) {
        
        int n = word.size();
        node *p= root;
        
        for(int i=0;i<n;i++)
        {
            if(!p->m.count(word[i]))
                return 0;
            p=p->m[word[i]];
        }
        
        return p->end;
        
    }
    
    bool startsWith(string word) {
        
        int n = word.size();
        node *p= root;
        for(int i=0;i<n;i++)
        {
            if(!p->m.count(word[i]))
                return 0;
            p=p->m[word[i]];
        }
        
        return 1;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */