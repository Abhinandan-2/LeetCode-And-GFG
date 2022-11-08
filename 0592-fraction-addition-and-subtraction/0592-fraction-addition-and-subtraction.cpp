class Solution {
public:
    string fractionAddition(string a) {
        int n = a.size(),i=0,sum=0,num,den,lcm,gcd,mainSign=0,mul;
        vector<pair<int,int>> val;
        string ans,sign;
        if(a[0]!='-') sign.push_back('+');
        while(i<n){
            if(a[i]=='-'||a[i]=='+') sign.push_back(a[i++]);
            else{
                num =0 ;
                while(i<n&&a[i]!='+'&&a[i]!='-'&&a[i]!='/') {num *= 10;num += (a[i++]-48);}
                i++;
                den =0 ;
                while(i<n&&a[i]!='+'&&a[i]!='-'&&a[i]!='/') {den *= 10;den += (a[i++]-48);}
                val.push_back({num,den});
            }
        }
        if(sign.size()==1){
            gcd = __gcd(val[0].first,val[0].second);
            sum = val[0].first/gcd;
            lcm = val[0].second/gcd;
            if(sign[0]=='-') sum *=-1;
            ans = to_string(sum)+"/"+to_string(lcm);
            return ans;
        }
        gcd = val[0].second;
        mul = val[0].second;
        for(int i=1;i<val.size();i++) {gcd = __gcd(gcd,val[i].second);mul *= val[i].second;}
        lcm = mul/gcd;
        for(int i=0;i<val.size();i++){
            num = lcm/val[i].second;
            num *= val[i].first;
            if(sign[i]=='-') num*=-1;
            sum += num;
        }
        if(sum<0) {mainSign =1;sum *=-1;}
        gcd = __gcd(sum,lcm);
        sum/=gcd;
        lcm/=gcd;
        if(mainSign==1) sum *=-1;
        ans = to_string(sum)+"/"+to_string(lcm);
        return ans;
    }
};