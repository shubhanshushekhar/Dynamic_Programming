#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int ar[2001];

bool rec(int sum,int n)
{
   if(sum < 0 or n < 0) return false;
   if(sum==0) return true;

   return rec(sum, n-1) or rec(sum-ar[n], n-1);
}


int main()
{
   int i, j, sum, n;
   cin >> n;
   for(i=0;i<n;i++) cin >> ar[i];

   sum = accumulate(ar, ar+n, 0);
   if(rec(sum/2,n-1)) cout << "Possible";
   else cout << "Not Possible";
}
