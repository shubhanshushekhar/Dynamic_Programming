#include <iostream>
#include<vector>

using namespace std;

int main()
{
   int i, j, wt, n;
   cin >> n >> wt;
   vector<pair<int,int> > val(n);
   for(i=0;i<n;i++) cin >> val[i].first >> val[i].second;
   vector<vector<int> > dp(n+1, vector<int>(wt,0));

   for(i=0;i<n;i++)
   {
      for(j=0;j<=wt;j++)
      {
         if(val[i].second>=j) dp[i+1][j] = max(dp[i][j], dp[i][j-val[i].second]+val[i].first);
         else dp[i+1][j] = dp[i][j];
      }
   }

   cout << dp[n][wt] << endl;
}
