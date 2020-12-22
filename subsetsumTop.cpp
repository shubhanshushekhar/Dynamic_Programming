#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> >dp(200,vector<int>(200,-1));
int ar[2001];

bool rec(int sum, int n)
{
   if(sum<0 or n<0) return false;
   if(sum==0) return true;
   if(dp[sum][n]!=-1) return dp[sum][n];
   
   dp[sum][n] = rec(sum,n-1) or rec(sum-ar[n],n-1);
   if(dp[sum][n]==true) return true;
   else  return false;
   
}

int main()
{
   int i, j, n, sum;
   cin >> n >> sum;
   for(i=0;i<n;i++) cin >> ar[i];

   if(rec(sum,n-1)) cout << "Possible";
   else cout << "Not Possible";

}
