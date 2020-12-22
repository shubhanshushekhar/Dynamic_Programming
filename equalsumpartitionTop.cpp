#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int ar[10001];
vector<vector<int> > dp(200, vector<int>(200,-1));
//int dp[100][100]={-1};
bool rec(int sum, int n)
{
   if (sum<0 or n<0) return false;
   if(sum==0) return true;
   if(dp[sum][n]!=-1) return dp[sum][n];

   dp[sum][n] = rec(sum,n-1) or rec(sum-ar[n],n-1);
   if(dp[sum][n]==true) return true;
   else return false;
}
int main()
{
   int i, j, n;
   cin >> n;
   for(i=0;i<n;i++) cin >> ar[i];
   int sum = accumulate(ar,ar+n,0);
   if(sum&1) cout << "Not Possible1";
   else if(rec(sum/2, n-1)) cout << "Possible";
   else cout << "Not Possible";
}
