class Solution {
public:
    void find_no(vector<vector<char>> &a,int i,int j,int &c)
{
    bool b;
    do
    {
        c++;
        if(c==10)
            return ;
        b=1;
        if(b){
        for(int k=0;k<9;k++)
        {
            if(a[i][k]==c+48)
            {
                b=0;
                break;
            }
        }}
        if(b){
        for(int k=0;k<9;k++)
        {
            if(a[k][j]==c+48)
            {
                b=0;
                break;
            }
        }}
        if(b){
        int h = i/3;
        h*=3;
        int k = j/3;
        k*=3;
        int l =3,g,p,o;
        while(l--)
        {
            p=k;
            g =3;
            while(g--)
            {
                if(a[h][p]==c+48)
                {
                    b=0;
                    break;
                }
                p++;
            }
            h++;

        }}

    }while(!b);
    return ;

}

bool bt(vector<vector<char>> &a,int i,int j,int c)
{
    if(j==9)
    {
        i++;
        j=0;
    }
    if(i==9)
    {
        return 1;
    }
    bool b=0;
    if(a[i][j]=='.')
    {
        do
        {
            find_no(a,i,j,c);
            if(c==10)
            {
                a[i][j]='.';
                return false;
            }
            a[i][j]=c+48;
            b = bt(a,i,j+1,0);
        }while(!b);
    }
    return bt(a,i,j+1,0);
}

    
    void solveSudoku(vector<vector<char>>& a) {
         bool b = bt(a,0,0,0);
          return ;
    }
};