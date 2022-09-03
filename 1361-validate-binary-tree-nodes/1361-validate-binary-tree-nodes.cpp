class Solution {
    
    int find_set(int a,vector<int> &p)
    {
        if(a==p[a])
            return a;
        return p[a] = find_set(p[a],p);
    }
    
    void union_set(int x,int y,vector<int> &p,vector<int> &s)
    {
        if(s[x]>s[y])
            swap(x,y);
        p[x] = y;
        s[y] += s[x];
        return ;
    }
    
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        
        vector<int> in(n,0),p(n,0),s(n,0);
        int x, y;
        for(int i=0;i<n;i++)
            p[i] = i;
        
        for(int i=0;i<left.size();i++)
        {
            if(left[i]!=-1){
            in[left[i]]++;
            x = find_set(i,p);
            y = find_set(left[i],p);
            if(x==y)
                return 0;
            union_set(x,y,p,s);
            }
        }
        for(int j=0;j<right.size();j++)
        {
            if(right[j]!=-1){
            in[right[j]]++;
            x = find_set(j,p);
            y = find_set(right[j],p);
            if(x==y)
                return 0;
            union_set(x,y,p,s);
            }
        }
        
        int o=0,f=0;
        for(int i=0;i<n;i++)
        {
            if(in[i]>1) return 0;
            if(in[i]==0) f++;
        }
        if(f!=1) return 0;
        return 1;
        
    }
};