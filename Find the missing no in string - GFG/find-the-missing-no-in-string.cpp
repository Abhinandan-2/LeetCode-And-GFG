// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& a)
{
    string k ;
    int n =a.size(),h,f,ans,turn,st,next;
    for(int i=1;i<=6;i++)
    {
        st =-1;
        f=0;
        h =i;
        k.clear();
        for(int u=0;u<i;u++)
        k += "9";
        turn = stoi(k);
        ans =-1;
        for(int j=0;j<n;)
        {
            if(st==-1)
            {
                if(j+h-1>=n)
                {
                    f=1;
                    break;
                }
                st = stoi(a.substr(j,h));
                j += h;
            }
            else
            {
                // if(st==turn-1)
                // {
                //     if(j+h-1>=n)
                //     {
                //         f=1;
                //         break;
                //     }
                // }
                if(st==turn)
                h++;
                if(j+h-1>=n)
                {
                    f=1;
                    break;
                }
                next = stoi(a.substr(j,h));
                if(next==st+1)
                {
                    st = next;
                    j+=h;
                }
                else if(next==st+2)
                {
                    if(ans==-1){
                    st = next;
                    j+=h;
                    ans = next-1;
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                    
                }
                else
                {
                    if(st!=turn-1)
                    {
                        f=1;
                        break;
                    }
                    h++;
                    if(j+h-1>=n)
                    {
                        f=1;
                        break;
                    }
                    next = stoi(a.substr(j,h));
                    if(next==st+1)
                    {
                        st = next;
                        j+=h;
                    }
                    else if(next==st+2)
                    {
                        if(ans==-1){
                        st = next;
                        j+=h;
                        ans = next-1;
                        }
                        else
                        {
                            f=1;
                            break;
                        }
                    
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                }
            }
            // cout<<j<<" "<<st<<" "<<ans<<endl;
            
        }
        if(f==0)
        {
            if(ans!=-1)
            return ans;
        }
    }
    return -1;
}