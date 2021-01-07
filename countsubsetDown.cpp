#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int i, j, n, sum;
   cin >> n >> sum;
   vector<int> v(n);
   for(i=0;i<n;i++) cin >> v[i];
   vector< vector<int>  > dp(n+1, vector<int>(sum+1,-1));
   for(i=0;i<=n;i++) dp[i][0] = 1;
   for(i=0;i<n;i++)
   {
      for(j=1;j<=sum;j++)
      {
         if(j>=v[i])
         {
            if(dp[i][j-v[i]]!=-1) dp[i+1][j] = dp[i][j-v[i]];
            if(dp[i][j]!=-1 and dp[i+1][j]>0) dp[i+1][j] +=dp[i][j];
            else dp[i+1][j] = dp[i][j];
         }
        
         else if(dp[i][j]!=-1)  dp[i+1][j] =max( dp[i][j],0);

      }
   }

  cout << dp[n][sum] << endl;

  for(i=0;i<=n;i++) 
  {
     for(j=0;j<=sum ;j++) 
        cout << dp[i][j] << " ";

        cout << endl;
  }
}
