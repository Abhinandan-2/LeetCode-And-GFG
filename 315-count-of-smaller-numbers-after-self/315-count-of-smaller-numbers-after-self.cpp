class Solution {
public:
    
    
    void merge(vector<pair<int,int>> &a,vector<int> &ans,int s,int m,int e)
    {
        vector<pair<int,int>> h;
        //cout<<s<<" "<<m<<" "<<e<<endl;
        int count =0 ;
        int i=s,j = m+1;
        while(i<=m&&j<=e)
        {
           // cout<<i<<" "<<j<<endl;
            if(a[j].first<a[i].first)
            {
                //cout<<1<<endl;
                count++;
                h.push_back(a[j]);
                j++;
                
            }
            else
            {
                ans[a[i].second] += count;
                h.push_back(a[i]);
                i++;
            }
         //   cout<<i<<" "<<j<<endl;
        }
        while(j<=e)
        {
            h.push_back(a[j]);
            j++;
        }
        while(i<=m)
        {
            ans[a[i].second] += count;
            h.push_back(a[i]);
            i++;
        }
        
        for(int i=s,k=0;i<=e;i++,k++)
        {
            a[i] = h[k];
        }
        return ;
        
    }
    
    
    void mergeSort(vector<pair<int,int>> &a,vector<int> &ans,int s,int e)
    {
        int n = a.size();
        //cout<<s<<" "<<e<<endl;
        if(s==e)
            return ;
        
        int m = s+(e-s)/2;
        mergeSort(a,ans,s,m);
        mergeSort(a,ans,m+1,e);
        merge(a,ans,s,m,e);
        
        return ;
        
        
    }
    
    
    vector<int> countSmaller(vector<int>& a) {
        
        int n = a.size();
        vector<pair<int,int>> v(n);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            v[i] = {a[i],i};
        }
        
        mergeSort(v,ans,0,n-1);
        
        return ans;
        
        
    }
};