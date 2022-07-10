class Solution {
public:
    
    vector<int> giveMn(vector<int> &a)
    {
        stack<int> s;
       
        int n = a.size();
        vector<int> sm(n);
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&a[s.top()]>a[i])
            {
                sm[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty())
        {
            sm[s.top()] = n;
            s.pop();
        }
        
        return sm;
    }
    
    int validSubarraySize(vector<int>& a, int th) {
        
        int n = a.size(),dis,num;
        vector<int> left,right,b,div(n);
        left = giveMn(a);
        reverse(a.begin(),a.end());
        right = giveMn(a);
        reverse(a.begin(),a.end());
        reverse(right.begin(),right.end());
        for(int i=1;i<=n;i++)
            div[i-1] = th/i;
        for(int i=0;i<n;i++)
        {
            dis = left[i]-i+i-(n-right[i]-1)-1;
            num = div[dis-1];
            if(num<a[i])
                return dis;
        }
        return -1;
        
    }
};