#include <iostream>
using namespace std;

int main()
{
   int i, j, n, sum;
   cin >> n;
   int ar[n+1];
   for(i=0;i<n;i++) cin >> ar[i];
   sum=0;
   for(i=0;i<n;i++) sum += ar[i];
   if(sum&1)
   {
      cout << "Not Possible";
      return 0;
   }
   bool dp[n+1][sum+1];
   memset(dp,false, sizeof(dp));
   for(i=0;i<=n;i++) dp[i][0] = true;
   for(i=0;i<n;i++) 
   {
      for(j=0;j<=sum;j++)
      {
         if(j-ar[i]>=0) dp[i+1][j] = dp[i][j] or dp[i][j-ar[i]];
         else dp[i+1][j] = dp[i][j];
      }
   }

   if(dp[n][sum]) cout << "Possible";
   else cout << "Not Possible";
}
