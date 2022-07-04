class node{
    

    
    public :
    
    char val;
    vector<node*> child;
    
    node(char c)
    {
        val = c;
        child.resize(26,NULL);
    }
    
};


class trie{
    
    node* root;
    
    public :
    
    trie()
    {
        root = new node('0');
    }
    
    int insert(string a,int n,int f)
    {
        node *p = root;
        int ans = -1;
        int k = a.size();
        for(int i=0;i<min(n,k);i++)
        {
            if(f==0)
            {
                if(p->child[a[i]-97]==NULL)
                {
                    node *t = new node(a[i]);
                    p->child[a[i]-97] = t;
                    p=t;
                }
                else
                {
                    p=p->child[a[i]-97];
                }
            }
            else
            {
                // cout<<a[i]<<" ";
                if(p->child[a[i]-97]==NULL)
                {
                    ans = i;
                    break;
                }
                else
                {
                    p=p->child[a[i]-97];
                }
            }
            // cout<<i<<" ";
        }
        
        if(f==0)
            return n;
        if(ans==-1)
            return min(n,k);
        return ans;
    }
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        
        trie Tree;
        int n = a[0].size();
        n = Tree.insert(a[0],n,0);
        for(int i=1;i<a.size();i++)
        {
            n = Tree.insert(a[i],n,1);
            // cout<<n<<" ";
            if(n==0)
                return "";
        }
        string ans = a[0].substr(0,n);
        return ans;
        
    }
};