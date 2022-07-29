dp[0][0]=0 ;
q.push({0,0,0});
while(!q.empty())
{
p = q.top();
q.pop();
v[p[0]][p[1]] = true ;
for(int k=0;k<4;k++)
{
x1 = p[0]+x[k];
y1 = p[1]+y[k];
cost = a[p[0]][p[1]] == k+1 ? 0 :1 ;
if(x1>=0&&x1<n&&y1>=0&&y1<m&&v[x1][y1]==false&&p[2]+cost<dp[x1][y1])
{
dp[x1][y1] = p[2]+cost;
q.push({x1,y1,dp[x1][y1]});
}
}
}
return dp[n-1][m-1];
}
};
```