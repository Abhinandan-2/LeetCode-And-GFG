class Solution {
public:
    string fractionAddition(string a) {
        vector<pair<int,int>> val;
        vector<char> sign;
        int n = a.size(),i=0,sum=0,num,den,lcm,gcd,mainSign=0,mul;
        string ans;
        if(a[0]!='-') sign.push_back('+');
        while(i<n){
            if(a[i]=='-'||a[i]=='+'){
                // cout<<i<<" "<<a[i]<<endl;
                sign.push_back(a[i]);
                i++;
            }
            else{
                
                num =0 ;
                while(i<n&&a[i]!='+'&&a[i]!='-'&&a[i]!='/'){
                    num *= 10;
                    num += (a[i]-48);
                    // cout<<i<<" "<<num<<" ";
                    i++;
                }
                // cout<<num<<" ";
                i++;
                den =0 ;
                 while(i<n&&a[i]!='+'&&a[i]!='-'&&a[i]!='/'){
                    den *= 10;
                    den += (a[i]-48);
                    // cout<<i<<" "<<den<<" ";
                    i++;
                }
                // cout<<i<<endl;
                val.push_back({num,den});
            }
            // cout<<i<<"->";
            // for(auto i:sign) cout<<i<<" ";
            // cout<<endl;
        }
        // for(auto i:sign) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:val) cout<<i.first<<" "<<i.second<<endl;
        if(sign.size()==1){
            gcd = __gcd(val[0].first,val[0].second);
            sum = val[0].first/gcd;
            lcm = val[0].second/gcd;
            if(sign[0]=='-') sum *=-1;
            ans = to_string(sum);
            ans += "/";
            ans += to_string(lcm);
            return ans;
        }
        gcd = val[0].second;
        mul = val[0].second;
        for(int i=1;i<val.size();i++){
            gcd = __gcd(gcd,val[i].second);
            mul *= val[i].second;
        }
        // cout<<gcd<<" "<<mul<<" ";
        lcm = mul/gcd;
        sum =0 ;
        for(int i=0;i<val.size();i++){
            num = lcm/val[i].second;
            num *= val[i].first;
            if(sign[i]=='-') num*=-1;
            sum += num;
        }
        if(sum<0){
            mainSign =1 ;
            sum *=-1;
        }
        gcd = __gcd(sum,lcm);
        sum/=gcd;
        lcm/=gcd;
        if(mainSign==1) sum *=-1;
        ans = to_string(sum);
        ans += "/";
        ans += to_string(lcm);
        return ans;
    }
};