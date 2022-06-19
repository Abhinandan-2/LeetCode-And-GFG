class Solution {
public:
    
    static bool com(string &a,string &b)
    {
        int n = a.size() ,  m = b.size();
     
        if(n==m)
        {
           return a<b;
        }
        
        return n<m;
        
    }
    
    string kthLargestNumber(vector<string>& a, int k) {
        int n = a.size();
        sort(a.begin(),a.end(),com);
        // for(auto i:a)
        //     cout<<i<<" ";
        return a[n-k];
        
    }
};