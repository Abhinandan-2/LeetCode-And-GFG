class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        
        int n = a.size(),p;
        long long sum=0,h;
        sort(a.begin(),a.end());
        for(auto i:a)
            sum+=i;
        
        if(n==1)
            return 1;
        // if(n==2)
        // {
        //     p = abs(a[0]-a[1]);
        //     if(p)
        //     p--;
        //     return sum-p;
        // }
//         if(n==3)
//         {
            
//             p = a[2]-a[1];
//             p = abs(p-a[0]);
//             if(p)
//                 p--;
//             return sum-p;
//         }
        
        h = sum/2;
        // cout<<h;
        if(a[n-1]>h)
        {
            h = sum-a[n-1];
            h *=2;
            h++;
            return h;
        }
        return sum;

//         priority_queue<int> q;
        
//         for(int i=0;i<n;i++)
//             q.push(a[i]);
        
//         while(q.size()>1)
//         {
//             p = q.top();
//             q.pop();
//             r = q.top();
//             q.pop();
//             p-=r;
//             if(p!=0)
//             q.push(p);
//         }
        
//         int rem;
//         if(q.empty())
//             rem=0;
//         else
//             rem = q.top()-1;
        
//         return sum-rem;
        
    }
};