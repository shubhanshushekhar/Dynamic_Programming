#include <iostream>
#include <vector>
using namespace std;

int main(){
   int i, j, sum, n;
   cin >> n >> sum;

   int ar[100];
   for(i=0;i<n;i++) cin >> ar[i];
   bool dp[100][100]={false};

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
