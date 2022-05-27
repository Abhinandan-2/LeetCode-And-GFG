class Solution {
public:
    string reversePrefix(string a, char c) {
        
        int f=-1 ,n = a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]==c)
            {
                f=i;
                break;
            }
        }
        if(f==-1)
            return a;
        reverse(a.begin(),a.begin()+f+1);
        return a;
        
        
    }
};