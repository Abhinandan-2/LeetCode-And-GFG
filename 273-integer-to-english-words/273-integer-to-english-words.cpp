class Solution {
    
    string call(int n,unordered_map<char,string> &m,unordered_map<char,string> &p,unordered_map<string,string> &v)
    {
        int h;
        string ans;
        if(n>=100)
        {
            h = n/100;
            n = n%100;
            ans += m[h+48];
            //cout<<h<<m[h-48];
            ans += " Hundred "; 
        }
        if(n>=10&&n<20)
        {
            ans += v[to_string(n)];
            ans += " ";
            return ans;
        }
        h = n/10;
        if(h!=0)
        {
            ans += p[h+48];
            ans += " ";
            n = n%10;
        }
        if(n!=0)
        {
            ans += m[n+48];
            ans += " ";
        }
        return ans;
    }
    
    
public:
    string numberToWords(int n) {
        
        if(n==0)
            return "Zero";
        
        unordered_map<char,string> m,p;
        unordered_map<string,string> v;
        int k;
        m['1'] = "One";
        m['2'] = "Two";
        m['3'] = "Three";
        m['4'] = "Four";
        m['5'] = "Five";
        m['6'] = "Six";
        m['7'] = "Seven";
        m['8'] = "Eight";
        m['9'] = "Nine";
        p['2'] = "Twenty";
        p['3'] = "Thirty";
        p['4'] = "Forty";
        p['5'] = "Fifty";
        p['6'] = "Sixty";
        p['7'] = "Seventy";
        p['8'] = "Eighty";
        p['9'] = "Ninety";
        v["10"] = "Ten";
        v["11"] = "Eleven";
        v["12"] = "Twelve";
        v["13"] = "Thirteen";
        v["14"] = "Fourteen";
        v["15"] = "Fifteen";
        v["16"] = "Sixteen";
        v["17"] = "Seventeen";
        v["18"] = "Eighteen";
        v["19"] = "Nineteen";
        
        string ans;
        if(n>=1000000000)
        {
            k = n/1000000000;
            n = n%1000000000;
            ans += call(k,m,p,v);
            ans += "Billion ";
        }
        if(n>=1000000)
        {
            k = n/1000000;
            n = n%1000000;
            ans += call(k,m,p,v);
            ans += "Million ";
        }
        if(n>=1000)
        {
            k = n/1000;
            n = n%1000;
            ans += call(k,m,p,v);
            ans += "Thousand ";
        }
        ans += call(n,m,p,v);
        while(ans.size()>0&&ans.back()==' ')
            ans.pop_back();
        return ans;
        
    }
};