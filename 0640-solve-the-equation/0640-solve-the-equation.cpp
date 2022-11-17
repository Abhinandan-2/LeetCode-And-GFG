class Solution {
public:
    string solveEquation(string a) {
        
        int n = a.size(), lcoff =0 , lconst =0 , rcoff=0 , rconst =0 ,f=0 , help=0 ,i=0 , l=0, Const, Coff , noCoff = 1;
        
        while(i<n){
            // cout<<i<<" ";
            if(a[i]=='-'){
                if(f==0){
                    if(l==0) lconst += help;
                    else rconst += help;
                }
                else{
                    if(l==0) lconst -= help;
                    else rconst -= help;
                }
                f=1;
                i++;
                help =0;
                noCoff =1;
            }
            else if(a[i]=='+'){
                if(f==0){
                    if(l==0) lconst += help;
                    else rconst += help;
                }
                else{
                    if(l==0) lconst -= help;
                    else rconst -= help;
                }
                f=0;
                i++;
                help=0;
                noCoff =1;
            }
            else if(a[i]>=48&&a[i]<=57){
                help=0;
                noCoff = 0;
                while(i<n&&a[i]>=48&&a[i]<=57){
                    help *=10;
                    help += (a[i]-48);
                    i++;
                }
                // if(f==1) -1*help;
                // if(i==n) rconst += help;
                // else if(a[i]=='x'){
                //     if(l==0) lcoff+= help;
                //     else rcoff+= help;
                // }
                // else if(a[i]=='=') lconst += help;
                // else if(a[i]=='-'||a[i]=='+'){
                //     if(l==0) lconst += help;
                //     else rconst += help;
                // }
            }
            else if(a[i]=='='){
                if(f==0){
                    lconst += help; 
                }
                else{
                    lconst -= help;
                }
                l=1;
                i++;
                f=0;
                help=0;
                noCoff =1;
            }
            else if(a[i]=='x'){
                if(l==0){
                    if(noCoff==1){
                        if(f==0) lcoff++;
                        else lcoff--;
                    }
                    else{
                        if(f==0) lcoff+= help;
                        else lcoff -= help;
                    } 
                }
                else{
                    if(noCoff==1){
                        if(f==0) rcoff++;
                        else rcoff--;
                    }
                    else{
                        if(f==0) rcoff+= help;
                        else rcoff -= help;
                    } 
                }
                help=0;
                f=0;
                i++;
                noCoff = 1;
            }
        }
        if(f==0) rconst += help;
        else rconst -= help;
        
        // cout<<lcoff<<" "<<rcoff<<" "<<lconst<<" "<<rconst;
        Const = rconst-lconst;
        Coff = lcoff-rcoff;
        
        if(Coff==0){
            // if(Const==0)
            if(Const==0) return "Infinite solutions";
            return "No solution";
        }
        
        int ans = Const/Coff;
        string res  = "x=" + to_string(ans);
        
        return res;
        
    }
};


// "x+5-3+x=6+x-2"
// "x=x"
// "2x=x"
// "99x=99"
// "x+6=x+8"
// "0x=0"