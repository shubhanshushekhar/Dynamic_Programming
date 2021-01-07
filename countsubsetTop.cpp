#include <iostream>
#include <vector>
using namespace std;

vector<int> v(n);
vector< vector<int> > dp(100, vector<int>(100,0));

int rec(int sum, n)
{
   if(sum==0) return 1;
   if(dp[sum][n]!=-1) return dp[sum][n];
   else
   {
      dp[sum][n] = rec(sum, n)+rec(sum-v[i]);
      return dp[sum][n];
   }
}

int main()
{
   int n, sum;
   cin >> n >> sum;
   for(int i=0;i<n;i++) cin >> v[i];
   cout << rec(sum, n-1);
}
