// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int n, int m) 
    {
        int  l =0 , r = m-1 , u =0 , d = n-1 , f =0 ;
        vector<int> ans;
        while(l<=r&&u<=d)
        {
            if(f==0)
            {
                for(int i=l;i<=r;i++)
                {
                    ans.push_back(a[u][i]);
                }
                u++;
            }
            else if(f==1)
            {
                for(int i=u;i<=d;i++)
                {
                    ans.push_back(a[i][r]);
                }
                r--;
            }
            else if(f==2)
            {
                for(int i=r;i>=l;i--)
                {
                    ans.push_back(a[d][i]);
                }
                d--;
            }
            else
            {
                for(int i=d;i>=u;i--)
                {
                    ans.push_back(a[i][l]);
                }
                l++;
            }
            f++;
            f= f%4;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends