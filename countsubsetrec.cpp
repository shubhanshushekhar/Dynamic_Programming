#include <iostream>
using namespace std;
int ans=0;
int ar[100];

void rec(int sum, int n)
{
   if(sum<0) return;
   if(sum==0) 
   {
      ans++;
      return;
   }

   if(n<0) return;
   rec(sum,n-1);
   rec(sum-ar[n],n-1);
}


int main()
{
   int i, j, n, sum;
   cin >> n >> sum;

   for(i=0;i<n;i++) cin >> ar[i];

   rec(sum, n-1);
   cout << ans;
}
