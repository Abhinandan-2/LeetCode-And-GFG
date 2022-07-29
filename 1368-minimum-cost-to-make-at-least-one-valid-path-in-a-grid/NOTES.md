```
class Solution {
public:
struct com
{
bool operator() (vector<int> &a,vector<int> &b)
{
return a[2]>b[2];
}
};
int minCost(vector<vector<int>>& a) {
int n = a.size() , m = a[0].size();
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
vector<vector<bool>> v(n,vector<bool> (m,false));
priority_queue<vector<int>,vector<vector<int>> , com> q;
vector<int> p;
int x1,y1,cost;
dp[0][0]=0 ;
q.push({0,0,0});