class Solution {
public:
    
    bool canMade(int num,unordered_map<int,int> m)
    {
        unordered_map<int,int> v;
        while(num)
        {
            if(!m.count(num%10))
                return 0;
            m[num%10]--;
            if(m[num%10]==0)
                m.erase(num%10);
            num/=10;
        }
        
        return 1;
    }
    
    bool reorderedPowerOf2(int n) {
        
        if(n==1)
            return 1;
        int digit = log2(n)/log2(10);
        digit++;
        unordered_map<int,int> m;
        while(n)
        {
            m[n%10]++;
            n/=10;
        }
        int lowest = pow(10,digit-1),num,numdigit;
        int lowestPower = log2(lowest)/log2(2);
        lowestPower++;
        while(lowestPower<31)
        {
            // cout<<lowestPower<<" ";
            num = pow(2,lowestPower);
            numdigit = log2(num)/log2(10);
            numdigit++;
            if(numdigit>digit)
                break;
            if(canMade(num,m))
                return 1;
            lowestPower++;
        }
        
        return 0;
        
    }
};

