class Solution {
public:
    vector<string> removeComments(vector<string>& a) {
        vector<string> ans;
        string h ;
        int n = a.size() , f =0 ,len;
        for(int i=0;i<n;i++){
            len = a[i].size();
            for(int j=0;j<len;j++){
                if(j<len-1&&a[i][j]=='/'&&a[i][j+1]=='/'){
                    if(f==0) break;
                    
                }
                else if(f==0&&j<len-1&&a[i][j]=='/'&&a[i][j+1]=='*'){
                    f=1;
                    j++;
                }
                else if(f==1&&j<len-1&&a[i][j]=='*'&&a[i][j+1]=='/'){
                    f=0;
                    j++;
                }
                else{
                    if(f==0) h.push_back(a[i][j]);
                }
            }
            if(f==0&&h.size()!=0) ans.push_back(h);
            if(f==0) h.clear();
        }
        return ans;
        
    }
};

// ["/*Test program */","int main()", "{ ", "  // variable de/*claration ", "int a, b, c;"," dfdsdsd ", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]