class Solution {
    
//     vector<string> allPermutation(string &a)
//     {
//         int n = a.size(),cn=0;
//         unordered_set<string> sol;
//         vector<string> ans;
//         string res;
//         makePermutation(a,0,res,sol);
//         for(auto i:sol) ans.push_back(i);
//         return ans; 
//     }
    
    void makePermutation(string &a,int i,string &res,unordered_set<string> &ans)
    {
        int n = a.size();
        if(i==n)
        {
            ans.insert(res);
            return ;
        }
        if(a[i]>=97&&a[i]<=122)
        {
            res.push_back(a[i]);
            makePermutation(a,i+1,res,ans);
            res.pop_back();
            return ;
        }
        
        makePermutation(a,i+1,res,ans);
        res.push_back(a[i]);
        makePermutation(a,i+1,res,ans);
        res.pop_back();
        return ;
    }
    
    // string convert(string a)
    // {
    //     reverse(a.begin(),a.end());
    //     for(int i=0;i<a.size();i++)
    //     {
    //         if(a[i]=='(')
    //             a[i]=')';
    //         else if(a[i]==')')
    //             a[i] ='(';
    //     }
    //     return a;
    // }
    
    bool isValid(string &a)
    {
        int s=0;
        for(auto i:a)
        {
            if(i=='(')
                s++;
            else if(i==')')
            {
                if(s==0)
                    return 0;
                s--;
            }
        }
        if(s!=0)
            return 0;
        return 1;
    }
    
public:
    vector<string> removeInvalidParentheses(string a) {
        
        
        int n = a.size(),cn=0;
        unordered_set<string> sol;
        vector<string> ans,vec;
        string res;
        makePermutation(a,0,res,sol);
        for(auto i:sol)
            if(isValid(i))
                ans.push_back(i);
        int mx = INT_MIN;
        for(auto i:ans)
        {
            mx = max(mx,(int)i.size());
        }
        
        for(auto i:ans)
        {
            if(i.size()==mx)
                vec.push_back(i);
        }
        if(vec.size()==0)
            vec.push_back("");
        return vec; 
//         int t=0;
//         for(auto i:a)
//         {
//             if(i=='(') t--;
//             else if(i==')') t++;
//         }
        
//         vector<string> vec,ans;
        
//         if(t>=0)
//         {
//             vec = allPermutation(a,t);
            
//         }
//         else{
//         a = convert(a);
//             cout<<a<<endl;
//         t *= -1;
//         vec = allPermutation(a,t);
//             for(auto i:vec) cout<<i<<" ";
//             cout<<endl;
//         for(int i=0;i<vec.size();i++)
//             vec[i] = convert(vec[i]);
//             for(auto i:vec) cout<<i<<" ";
//             cout<<endl;
//         }
        
//         for(int i=0;i<vec.size();i++)
//         {
//             if(isValid(vec[i]))
//                 ans.push_back(vec[i]);
//         }
//         if(ans.size()==0)
//             ans.push_back("");
//         return ans;
    }
};


/*class Solution {
    
    vector<string> allPermutation(string &a)
    {
        int n = a.size(),cn=0,t=0;
        if(n==0)
            return {};
        unordered_set<string> sol;
        vector<string> ans;
        string res;
        for(auto i:a) {
            if(i==')') t++;
            else if(i=='(') t--;
        }
        makePermutation(a,0,cn,t,res,sol);
        for(auto i:sol) ans.push_back(i);
        return ans;
        
    }
    
    void makePermutation(string &a,int i,int cn,int t,string &res,unordered_set<string> &ans)
    {
        int n = a.size();
        if(i==n)
        {
            if(cn==t)
            ans.insert(res);
            return ;
        }
        if(cn==t||a[i]=='('||(a[i]>=97&&a[i]<=122))
        {
            res.push_back(a[i]);
            makePermutation(a,i+1,cn,t,res,ans);
            res.pop_back();
            return ;
        }
        
        makePermutation(a,i+1,cn+1,t,res,ans);
        res.push_back(a[i]);
        makePermutation(a,i+1,cn,t,res,ans);
        res.pop_back();
        return ;
    }
    
    string convert(string a)
    {
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='(')
                a[i]=')';
            else if(a[i]==')')
                a[i] ='(';
        }
        return a;
    }
    
    void multiplyAllstring(vector<vector<string>> &res,vector<string> &vec,vector<string> &ans,int i)
    {
        int n = res.size();
        if(i==n)
        {
            string help = makeString(vec);
            ans.push_back(help);
            return ;
        }
        for(int j=0;j<res[i].size();j++)
        {
            vec.push_back(res[i][j]);
            multiplyAllstring(res,vec,ans,i+1);
            vec.pop_back();
        }
        
        return ;
    }
    
    string makeString(vector<string> &vec)
    {
        string ans;
        for(auto i:vec)
            ans += i;
        return ans;
    }
    
public:
    vector<string> removeInvalidParentheses(string a) {
        
        int n = a.size(), last = 0 ,s =0 , cn =0 ;
        vector<vector<string>> res;
        vector<string> vec,ans;
        string help;
        for(int i=0;i<n;i++)
        {
            if(a[i]==')')
            {
                if(s>0)
                    s--;
                else
                    cn++;
                // if(s.empty())
                // {
                //     // cout<<"haha";
                //     if(i-1!=last)
                //     {
                //         help = a.substr(last+1,i-last);
                //         res.push_back(allPermutation(help));
                //     }
                //     last = i;
                // }
                // else
                // {
                //     s.pop();
                // }
            }
            else if(a[i]=='(')
            {
                if(s==0)
                {
                    if(cn!=0)
                    {
                        help = a.substr(last,i-last);
                        vec = allPermutation(help);
                        if(vec.size()!=0)
                        res.push_back(vec);
                        cn=0;
                        last = i;
                    }
                }
                s++;
                // s.push(1);
            }
        }
        
        help = a.substr(last,n-last);
        cout<<a<<" "<<help<<endl;
        // cout<<help<<" "<<cn;
        if(s==0)
        {
            if(cn==0)
            res.push_back({help});
            else
            {
                vec = allPermutation(help);
                // cout<<4;
                // for(auto i:vec) cout<<i<<" ";
                if(vec.size()!=0)
                res.push_back(vec);
            }
        }
        else 
        {
            help = convert(help);
            // cout<<help;
            vec = removeInvalidParentheses(help);
            for(int i=0;i<vec.size();i++)
                vec[i] = convert(vec[i]);
            res.push_back(vec);
        }
        // for(auto i:res)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        vec.clear();
        multiplyAllstring(res,vec,ans,0);
        return ans;
        
    }
};


"x("
"()())()"
"(a)())()"
")("
"()())w)"
"(a)())()"
")("
"()())()((())()(("
"(w(()()"
"(r(()()("
"(((()(()"

*/