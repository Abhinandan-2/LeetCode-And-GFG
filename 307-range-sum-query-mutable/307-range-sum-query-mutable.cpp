class node{
    
    public :
    int val ,l,r;
    node* left;
    node *right;
    node()
    {
        val = 0;
        left = NULL;
        right = NULL;
        l = -1;
        r = -1;
    }
    
};


class segTree{
    
    node *root;
    
    node* createTree(vector<int> &a,int s,int e)
    {
        node *t = new node();
        t->l = s;
        t->r = e;
        if(s==e)
        {
            t->val = a[s];
            return t;
        }
        
        int m = s+(e-s)/2;
        t->left = createTree(a,s,m);
        t->right = createTree(a,m+1,e);
        t->val = t->left->val+t->right->val;
        return t;
    }
    
    void updateTree(int in,int v,node *p)
    {
        if(p->l==in&&p->r==in)
        {
            p->val = v;
            return ;
        }
        
        int m = p->l+(p->r-p->l)/2;
        if(in>=p->l&&in<=m)
            updateTree(in,v,p->left);
        else
            updateTree(in,v,p->right);
        p->val = p->left->val+p->right->val;
        return ;
    }
    
    int queryTree(int s,int e,node *p)
    {
        if(p->l>=s&&p->r<=e)
            return p->val;
        if(s>p->r||e<p->l)
            return 0;
        
        int x = queryTree(s,e,p->left);
        int y = queryTree(s,e,p->right);
        return x+y;
    }
    
    public :
    
    void build(vector<int> &a)
    {
        int n = a.size();
        root = createTree(a,0,n-1);
        return ;
    }
    
    void update(int in,int v)
    {
        updateTree(in,v,root);
        return ;
    }
    
    int query(int s,int e)
    {
        return queryTree(s,e,root);
    }
    
    
    
};


class NumArray {
    
    segTree s;
    
public:
    
    NumArray(vector<int>& a) {
        
        s.build(a);
    }
    
    void update(int index, int val) {
        
        s.update(index,val);
        return ;
    }
    
    int sumRange(int left, int right) {
        
        return s.query(left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */