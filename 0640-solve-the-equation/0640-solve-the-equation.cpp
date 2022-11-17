class Solution {
public:
    string solveEquation(string a) {
        int n = a.size(), lcoff =0 , lconst =0 , rcoff=0 , rconst =0 ,f=0 , help=0 ,i=0 , l=0, noCoff = 1;
        while(i<n){
            if(a[i]=='-'||a[i]=='+'){
                if(f==1) help *= -1;
                l==0 ? lconst += help : rconst += help;
                a[i]=='-' ? f=1 : f =0 ;
                i++;
                help =0;
                noCoff =1;
            }
            else if(a[i]>=48&&a[i]<=57){
                help=0;
                noCoff = 0;
                while(i<n&&a[i]>=48&&a[i]<=57) help = (help*10)+(a[i++]-48);
            }
            else if(a[i]=='='){
                if(f==0) lconst += help; 
                else lconst -= help;
                l=1;
                i++;
                f=0;
                help=0;
                noCoff =1;
            }
            else if(a[i]=='x'){
                l==0 ? noCoff==1 ? f==0 ? lcoff++ : lcoff-- : f==0 ? lcoff+= help : lcoff -= help : noCoff==1 ? f==0 ? rcoff++ : rcoff-- : f==0 ? rcoff+= help : rcoff -= help;
                help=0;
                f=0;
                i++;
                noCoff = 1;
            }
        }
        if(f==0) rconst += help;
        else rconst -= help;
        if(lcoff-rcoff==0) return rconst-lconst==0 ? "Infinite solutions" : "No solution";
        return "x=" + to_string((rconst-lconst)/(lcoff-rcoff));
    }
};