class Solution {
public:
    
    static bool com(string &a,string &b)
    {
        int n = a.size() , m = b.size();
        if(n==m)
            return a<b;
        return n<m;
        
    }
    
    string kthLargestNumber(vector<string>& a, int k) {
        
        sort(a.begin(),a.end(),com);
        int n = a.size();
        int h = n-k;
        return a[h];
        
        
    }
};